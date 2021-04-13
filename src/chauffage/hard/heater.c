/*
 * heater.c
 *
 *  Created on: 19 mars 2021
 *      Author: rapha
 */
#include <chauffage/hard/g_hard.h>
#include <chauffage/hard/g_heater.h>



static uint8_t mirror_pwm_fan;
static uint8_t mirror_pwm_heat;



uint8_t heater_get_fan(void)
{
	return mirror_pwm_fan;
}

uint8_t heater_get_heat(void)
{
	return mirror_pwm_heat;
}



void heater_setPwm(uint8_t pwm)
	{
	mirror_pwm_heat = pwm;
    R_TMR_KC0_Stop();
    TKCDUTY02 = pwm;
    R_TMR_KC0_Start();
	}

void heater_setFan(uint8_t pwm)
	{
	mirror_pwm_fan = pwm;
    R_TMR_KC0_Stop();
    TKCDUTY02 = pwm*32;
    R_TMR_KC0_Start();
    }
