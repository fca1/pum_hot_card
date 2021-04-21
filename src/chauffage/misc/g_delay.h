/*
 * g_delay.h
 *
 *  Created on: 15 nov. 2014
 *      Author: fca
 */

#ifndef G_DELAY_H_
#define G_DELAY_H_

#include "g_automger.h"

extern volatile t_task_timer_cnt tick_1ms;
extern void delay_ms(t_task_timer_cnt delay_ms);
extern void delay_us(uint32_t delay_us);


#endif /* G_DELAY_H_ */
