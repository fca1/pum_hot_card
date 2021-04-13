/*
 * l_hardPin.h
 *
 *  Created on: 5 déc. 2013
 *      Author: fca
 */

#ifndef L_HARDPIN_H_
#define L_HARDPIN_H_

#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_serial.h"
#include "r_cg_timer.h"
#include <stdint.h>




#define SET_HEATER(x) 			{ P20_bit.no3 = (x); }
#define SET_FAN(x) 				{ P20_bit.no4 = (x); }







// Gestionnaire I2C
#define SOFT_DIR_SCL(e)     { PM1_bit.no0= (e);}
#define SOFT_SCL(e)			{ P1_bit.no0=(e); }
#define SOFT_DIR_SDA(e)     { PM1_bit.no1= (e); }
#define SOFT_SDA(e)			{ P1_bit.no1=(e); }
#define SOFT_READ_SDA()		P1_bit.no1

#define SENSOR_POWER(e) { P0_bit.no5 =(e); }

#define LED0 P20_bit.no1 // red
#define LED1 P20_bit.no2 // green
#define LED2 P20_bit.no0 // blue

// For compatibility
#define SET_LED_RED(x) { LED0 = !(x); }
#define TOGGLE_LED_RED() { LED0 = !LED0; }
#define SET_LED_GREEN(x) { LED1 = !(x); }
#define TOGGLE_LED_GREEN() { LED1 = !LED1; }
#define SET_LED_BLUE(x) { LED2 = !(x); }
#define TOGGLE_LED_BLUE() { LED2= !LED2; }
#define GET_LED_RED()  LED0
#define GET_LED_GREEN()  LED1
#define GET_LED_BLUE()  LED2




#endif /* L_HARDPINV200_H_ */
