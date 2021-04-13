/*
 * tempPid.c
 *
 *  Created on: 12 avr. 2021
 *      Author: frant
 */


#include "g_comm.h"


struct t_set_params			params =
{
.enabled=0,
.deciTemp=200,
.fan_min=80,
.fan_max=100,
.pwm_min=0,
.pwm_max=10,
.leds_report=1,

.pid_p=0,
.pid_i=0,
.pid_d=0,
};


struct t_status			status;






void pid_refresh(void)
{

}
