/*
 * heater.c
 *
 *  Created on: 19 mars 2021
 *      Author: rapha
 */
#include <chauffage/hard/g_hard.h>
#include <chauffage/hard/g_heater.h>
#include "r_cg_timer.h"



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
	uint32_t x = (uint32_t)_7CFF_TMKC_CYCLE0_VALUE*pwm;
	x>>=8;
    TKCDUTY02 = x&_7CFF_TMKC_CYCLE0_VALUE;
    R_TMR_KC0_Start();
	}

void heater_setFan(uint8_t pwm)
	{
	mirror_pwm_fan = pwm;
	R_TMR_KB2_Stop();
	uint32_t x = (uint32_t)_0C7F_TMKB_CYCLE20_VALUE*pwm;
	x>>=8;
    TKBCR21 = x&_0C7F_TMKB_CYCLE20_VALUE;
    R_TMR_KB2_Start();
    asm("nop");
    }
