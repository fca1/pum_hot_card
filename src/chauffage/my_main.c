/*
 * my_main.c
 *
 *  Created on: 9 avr. 2021
 *      Author: frant
 */

#include <chauffage/automaton/g_timerTask.h>
#include <chauffage/g_main_automaton.h>
#include <chauffage/g_my_main.h>
#include <chauffage/hard/g_emule_i2c.h>
#include <chauffage/hard/g_heater.h>
#include <chauffage/hard/g_si7053.h>
#include <chauffage/hard/l_hardPin.h>
#include <chauffage/misc/g_delay.h>
#include "r_cg_wdt.h"
#include "r_cg_serial.h"
#include "r_cg_it.h"
#include "g_comm.h"


uint8_t identity=0xFF;
uint64_t unique_serial_nber;





// Le systeme va emettre un message, et si ce message est sur la meme liaison série, alors
// Cela veut dire qu'il possede l'identite 0

static uint8_t fcnt_wait_serial_mirror_for_identity(void)
{
// Est ce que ce module a une identite.
uint8_t length;
struct t_comm_emit msg;
if (identity==0xFF)
	{
	length = comm_build_msg_identity(&msg,identity,unique_serial_nber);
	// Le module n'a pas d'identité, il en fait la demande sur les 2 voies.
	if (!g_uart1_tx_cnt)
		{
		R_UART1_Send((uint8_t*)&msg, length);
		delay_ms(20);
		struct t_comm_rcve *p=compute_serial1(&length);
		// Si c'est le meme message, alors mettre l'identité a 0
		if (p)
			if ((p->header.cmd==ASK_IDENTITY) && (unique_serial_nber==p->u.identity.identity))
				identity = 0;
				return 1;
		}
	if (!g_uart4_tx_cnt)
		{
		R_UART4_Send((uint8_t*)&msg, length);
		delay_ms(20);
		struct t_comm_rcve *p=compute_serial4(&length);
		if (p)
			if ((p->header.cmd==ASK_IDENTITY) && (unique_serial_nber==p->u.identity.identity))
				identity = 0;
				return 1;
		}
	return 0;
	}
return 1;
}






static void fcnt_init_hard(void)
{
    R_IT_Start();
    // Mise en place liaison serie.
        circularInit(&buf_rcve_uart1);
        circularInit(&buf_rcve_uart4);
        R_UART1_Start();
        R_UART4_Start();
    // Alimentwwation SI7053
    heater_setPwm(0);
    heater_setFan(0);
    SENSOR_POWER(1);
    i2c_configure();
    // Initialisation SI7053
    sensorSI7053_reset();
    sensorSI7053_read_serial(&unique_serial_nber);
    // Verifier que le message est le bon (numero de serie)
    uint8_t type_chip = ((uint8_t*)&unique_serial_nber)[3];
    while (type_chip<='0' || type_chip>='7')		// Attendre jusqu'a la mort de la liaison serie
    	{
    	delay_ms(300);
    	TOGGLE_LED_RED();
    	}
}





volatile t_task_timer_cnt save_time;
void my_main(void)
{
R_WDT_Restart();
fcnt_init_hard();			// Test du hard
while(!fcnt_wait_serial_mirror_for_identity());


// Lancer le PID
task_init_hard();
timerTaskInit();
while (1U)
{
save_time = tick_1ms;
while(save_time == tick_1ms)
	{
	ts_smart_tick_automaton();
	comm_manage_serial();
	}
timerTask_tick();
R_WDT_Restart();
}

}
