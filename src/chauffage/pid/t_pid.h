/*
 * t_pid.h
 *
 *  Created on: 13 nov. 2019
 *      Author: frant
 */

#ifndef PID_T_PID_H_
#define PID_T_PID_H_

#include <stdint.h>

struct t_pid
	{
	uint16_t consigne_deciDeg;
	uint32_t Kp;
	uint32_t Kd;
	uint32_t Ki;
	};



#endif /* PID_T_PID_H_ */
