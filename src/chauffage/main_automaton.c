

#include <chauffage/automaton/g_timerTask.h>
#include <chauffage/automaton/g_wrapperAutomatonTimer.h>
#include <chauffage/hard/g_hard.h>
#include <chauffage/pid/g_pid.h>
#include <stdio.h>
#include "r_cg_timer.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MINV(a,b) (((a)>(b)) ? (b):(a))
#define MAXV(a,b) (((a)<(b)) ? (b):(a))


t_automaton_ctxt ctxt_auto;

uint8_t ts_smart_tick_automaton(void)
{
return auto_motor_event(&ctxt_auto);
}


void TIMER_D(t_task_timer_cnt time,e_auto_evt evt,t_auto_data data)
{
wauto_start_timer(time,evt,data,0);
}


void TIMER(t_task_timer_cnt time,e_auto_evt evt)
{
wauto_start_timer(time,evt,0,0);
}
static void TIMER_SEC(t_task_timer_cnt time,e_auto_evt evt)
{
wauto_start_timer(time*1000L,evt,0,0);
}


void PUSH_D(e_auto_evt evt,t_auto_data data)
{
t_type_event temp = { .stv.evt=evt,.stv.data=data};
auto_push_event(&ctxt_auto,temp);
}


void PUSH(e_auto_evt evt)
{
PUSH_D(evt,0);
}



uint8_t IS_TIMER_RUNNING(e_auto_evt evt)
{
return wauto_is_timer_event_running(evt);
}


// static const t_type_event evt_none = {.stv.evt= EVT_NONE };

// Raccourci
#define END_TBL() { 0,                          NULL,                   NULL },
#define DEL_TIMER(evt)                          wauto_remove_timer(evt);



static void fcnt_none(t_type_event event) {(void)event; }
static void fcnt_init(t_type_event event) ;
static void fcnt_meas_can(t_type_event event) ;
static void fcnt_set_pwm(t_type_event event);
static void fcnt_stop_asser(t_type_event event);
static void fcnt_blink(t_type_event event);
static void fcnt_meas(t_type_event event);
static void fcnt_blink_bad(t_type_event event);
static void fcnt_locked(t_type_event event);
static void fcnt_compute_pid(t_type_event event);
static void fcnt_blink_test(t_type_event event);
static void fcnt_init_test(t_type_event event);
static void fcnt_unlock(t_type_event event);


static const t_automaton_state stateLocked[];



static const t_automaton_state stateInit[]=
{
		  { EVT_INIT_HARD,		fcnt_init,				NULL },
		  { EVT_RESULT_MEAS,	fcnt_compute_pid,		NULL },
		  { EVT_UNLOCKED,		fcnt_none,				NULL },
		  { EVT_TIMER_LOCKED,	fcnt_blink,			stateLocked },
		  END_TBL()
};


static const t_automaton_state stateLocked[]=

{
{ EVT_RESULT_MEAS,		fcnt_locked,			NULL },
{ EVT_UNLOCKED,			fcnt_unlock,		    stateInit },
END_TBL()
};




/**
* Cet état est utilisé par défaut, les évenements non déclarés dans les autres états
* sont traités ici. Il est possible de mettre un nouvel etat, par défaut NULL indique pas de
* changement d'état.
*/
static const t_automaton_state stateHook[]=
{
  { EVT_NONE,           fcnt_none,               NULL },
  { EVT_BLINK,			fcnt_blink,				 NULL },
  { EVT_BAD,			fcnt_blink_bad,			 NULL },
  { EVT_SET_PWM,		fcnt_set_pwm,		     NULL },
  { EVT_ASK_MEAS,		fcnt_meas,			     NULL },

  END_TBL()

};




void task_init_hard(void)
{
// Lancement de l'automate.
auto_init(&ctxt_auto,stateInit,wauto_auto_hook,stateHook);
PUSH(EVT_INIT_HARD);

}

static uint16_t value_pwm;
static uint16_t change_blink_cadence;



static void fcnt_set_pwm(t_type_event event)
{
heater_setPwm(event.stv.data/256);

}



static void fcnt_init_test(t_type_event event)
{
heater_setPwm(0);
value_pwm = 0;
PUSH_D(EVT_SET_PWM,value_pwm );
PUSH(EVT_BAD);
}


static void fcnt_init(t_type_event event)
{
value_pwm = 23000;
PUSH_D(EVT_SET_PWM,value_pwm );





pid_init();
pid_reset();				// Initialiser avec les valeurs par defaut.
PUSH(EVT_ASK_MEAS);
PUSH(EVT_BAD);
change_blink_cadence = 0;			// Est modifie si consigne NFC
}


static void fcnt_stop_asser(t_type_event event)
{
}


static void fcnt_blink(t_type_event event)
{
DEL_TIMER(EVT_BAD);
if (GET_LED_GREEN())
	{
	SET_LED_GREEN(0);
	TIMER(1980,EVT_BLINK);
	}
else
	{
	SET_LED_GREEN(1);
	TIMER(20,EVT_BLINK);
	}
}


static void fcnt_blink_bad(t_type_event event)
{
DEL_TIMER(EVT_BLINK);
if (GET_LED_RED())
	{
	SET_LED_RED(0);
	TIMER(100,EVT_BAD);
	}
else
	{
	SET_LED_RED(1);
	if (change_blink_cadence)
		TIMER(400,EVT_BAD);
	else
		TIMER(100,EVT_BAD);

	}
}





static void fcnt_blink_test(t_type_event event)
{
	DEL_TIMER(EVT_BLINK);
	if (GET_LED_GREEN())
		{
		SET_LED_GREEN(0);
		TIMER(1000,EVT_BAD);
		}
	else
		{
		SET_LED_GREEN(1);
		TIMER(1000,EVT_BAD);
		}
	}

static void fcnt_meas(t_type_event event)
{
int16_t deciDeg = sensorSI7053_read_decideg();
PUSH_D(EVT_RESULT_MEAS, deciDeg);
}






static void fcnt_compute_pid(t_type_event event)
{
// Mesure et résultat sous forme d'une tension entre 0  et 3300mV
uint16_t reference_deciDeg=event.stv.data;
int16_t te=pid_compute(reference_deciDeg);
int16_t error = pid_get_error();
if (te>=0)
	{
	value_pwm =value_pwm-MINV(value_pwm,te);

	}
else
	{
	value_pwm =value_pwm+MINV(65534-value_pwm,-te);
	}
PUSH_D(EVT_SET_PWM,value_pwm );
TIMER(700,EVT_ASK_MEAS);

if (abs(error)>20)
	{
	DEL_TIMER(EVT_TIMER_LOCKED);
	}
else
	{
	if (!IS_TIMER_RUNNING(EVT_TIMER_LOCKED))
		TIMER(5000, EVT_TIMER_LOCKED);
	}
}


static void fcnt_unlock(t_type_event event)
{
fcnt_blink_bad(event);
pid_init();
DEL_TIMER(EVT_ASK_MEAS);
PUSH(EVT_ASK_MEAS);
}


static void fcnt_locked(t_type_event event)
{
static uint8_t cnt=0;

uint16_t reference_mV=event.stv.data;
int16_t  error = pid_get_absolute_error(reference_mV);

// Le compteur va permettre une mesure régulière afin de verifier toutes les 3000ms que cela ne devie pas.
cnt++;


if (cnt>=100)
	{
	// Correctif fait, pas de vérification d'erreur avant 3 secondes.
	cnt=0;
	value_pwm -=4*error;
	PUSH_D(EVT_SET_PWM,value_pwm );
	}
else
	{
	// Toutes les 3 secondes, l'erreur ne doit pas dépasser cette limite de 25, sinon refaire calibration.
	if (abs(error)>40)
		{
		asm("nop");
		PUSH(EVT_UNLOCKED);
		return;
		}
	}

TIMER(3000,EVT_ASK_MEAS);
}







