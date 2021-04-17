/*
 * heater.h
 *
 *  Created on: 19 mars 2021
 *      Author: rapha
 */


#include <stdint.h>


extern void heater_setPwm(uint8_t pwm_percentage);
extern void heater_setFan(uint8_t pwm_percentage);
extern uint8_t heater_get_fan(void);
extern uint8_t heater_get_heat(void);




