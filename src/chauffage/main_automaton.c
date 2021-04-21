

#include <chauffage/automaton/g_timerTask.h>
#include <chauffage/automaton/g_wrapperAutomatonTimer.h>
#include <chauffage/hard/g_hard.h>
#include <chauffage/pid/g_pid.h>
#include <stdio.h>
#include "r_cg_timer.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "g_tempPid.h"

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
static void fcnt_locked(t_type_event event);
static void fcnt_compute_pid(t_type_event event);
static void fcnt_init_test(t_type_event event);





static const t_automaton_state stateInit[]=
{
		  { EVT_INIT_HARD,		fcnt_init,				NULL },
		  { EVT_RESULT_MEAS,	fcnt_compute_pid,		NULL },
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
event.stv.data = MINV(255,event.stv.data);
uint8_t pwm = MINV(event.stv.data,params.pwm_max);
pwm = MAXV(pwm,params.pwm_min);
if (!status.actif || !params.enabled)
	{
	pwm=0;
	heater_setPwm(pwm);
	heater_setFan(params.enabled ? params.fan_min: 0);
	return;
	}
heater_setPwm(pwm);
uint16_t xx= (params.fan_max-params.fan_min)*pwm;
xx = params.fan_min+xx/256;
xx = MINV(xx,params.fan_max);
xx = MAXV(xx,params.fan_min);
heater_setFan(xx);
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
value_pwm = 0;
PUSH_D(EVT_SET_PWM,value_pwm );





pid_reset(&pid_values);
PUSH(EVT_ASK_MEAS);
PUSH(EVT_BAD);
DEL_TIMER(EVT_BLINK)
TIMER(1,EVT_BLINK);

}


static void fcnt_stop_asser(t_type_event event)
{
}


static void fcnt_blink(t_type_event event)
{
static uint8_t flg_on = 0;
switch(params.leds_report)
	{
	case E_LED_OFF:
		SET_LED_GREEN(0);
		SET_LED_RED(0);
		SET_LED_BLUE(0);
		TIMER(4000,EVT_BLINK);
		return;
	case E_LED_ON:
		{
		if (!status.actif || !params.enabled)
			{
			TOGGLE_LED_GREEN()
			SET_LED_RED(0);
			SET_LED_BLUE(0);
			TIMER(4000,EVT_BLINK);
			return;
			}
		else
			{
			flg_on = !flg_on;
			if (!flg_on)
				{
				SET_LED_GREEN(0);
				SET_LED_RED(0);
				SET_LED_BLUE(0);
				TIMER(300,EVT_BLINK);
				return;
				}
			int16_t error = pid_get_error();
			// Plus l'erreur est grande, plus le ON sera long
			if (error>0)
				{
				SET_LED_BLUE(0)
				SET_LED_RED(1);
				TIMER(MINV(4000,error*10),EVT_BLINK);
				}
			else
				{
				SET_LED_BLUE(1)
				SET_LED_RED(0);
				TIMER(MINV(4000,-error*10),EVT_BLINK);
				}
			}
		}
		return;
	case E_LED_LOW:
		{
		flg_on = !flg_on;
		if (!status.actif || !params.enabled)
			{
			SET_LED_RED(0);
			SET_LED_BLUE(0);
			SET_LED_GREEN(0);
			return;
			}
		if (!flg_on)
			{
			SET_LED_GREEN(0);
			SET_LED_RED(0);
			SET_LED_BLUE(0);
			TIMER(3000,EVT_BLINK);
			return;
			}
		int16_t error = pid_get_error();
		// Plus l'erreur est grande, plus le ON sera long
		if (error>0)
			{
			SET_LED_BLUE(0)
			SET_LED_RED(1);
			TIMER(MINV(400,error),EVT_BLINK);
			}
		else
			{
			SET_LED_BLUE(1)
			SET_LED_RED(0);
			TIMER(MINV(400,-error),EVT_BLINK);
			}
		}


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
if (te<0)
	te=0;
value_pwm =te;
PUSH_D(EVT_SET_PWM,value_pwm );
TIMER(4000,EVT_ASK_MEAS);
}











