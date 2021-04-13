/*
 * g_delay.h
 *
 *  Created on: 15 nov. 2014
 *      Author: fca
 */

#ifndef G_DELAY_H_
#define G_DELAY_H_

#include <stdint.h>

extern volatile uint32_t tick_1ms;
extern void delay_ms(uint32_t delay_ms);
extern void delay_us(uint32_t delay_us);


#endif /* G_DELAY_H_ */
