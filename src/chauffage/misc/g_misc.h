/*
 * g_misc.h
 *
 *  Created on: 25 janv. 2014
 *      Author: fca
 */
#include "r_cg_macrodriver.h"

#ifndef G_MISC_H_
#define G_MISC_H_

#include <chauffage/misc/g_delay.h>

enum e_led
	{
	E_OFF,
	E_ON,
	E_BLINK,
	};

extern volatile enum e_led  stateLedGreen;
extern volatile enum e_led  stateLedRed;


#ifndef false
#define false 0
#endif
#ifndef true
#define true !false
#endif
#endif /* G_MISC_H_ */
