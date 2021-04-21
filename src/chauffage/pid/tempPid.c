/*
 * tempPid.c
 *
 *  Created on: 12 avr. 2021
 *      Author: frant
 */


#include "g_comm.h"
#include "g_pid.h"
#include "g_hard.h"
#include <stdlib.h>


struct t_set_params			params =
{
.enabled=1,
.deciTemp=650,
.fan_min=0,
.fan_max=255,
.pwm_min=00,
.pwm_max=255,
.leds_report=1,

.pid_p=0xA0000,
.pid_i=0x20000,
.pid_d=0x08000,
};


struct t_status			status;



struct t_status *  pid_refresh_status(void)
{
// Mettre a jour ce qui est dynamique
status.power_fan = heater_get_fan();
status.power_pwm = heater_get_heat();
status.deciTemp = sensorSI7053_read_decideg();
status.locked = abs(status.deciTemp-params.deciTemp)<20;
return &status;
}



void pid_refresh(struct t_set_params *ptr)
{
params = *ptr;
struct t_pid pid_values_init =
	{
	.Kp =ptr->pid_p,
	.Kd =ptr->pid_d,
	.Ki =ptr->pid_i,
	.consigne_deciDeg=ptr->deciTemp,							// Sortie = 20.0°C
	};

pid_reset(&pid_values_init);
status.deciTemp = ptr->deciTemp;
status.enabled = ptr->enabled;

}
