/*
 * g_tempPid.h
 *
 *  Created on: 12 avr. 2021
 *      Author: frant
 */

#ifndef CHAUFFAGE_PID_G_TEMPPID_H_
#define CHAUFFAGE_PID_G_TEMPPID_H_


#include "g_comm.h"

extern struct t_set_params	params;
extern struct t_status		status;


extern void pid_refresh(struct t_set_params *ptr);
extern struct t_status *  pid_refresh_status(void);

#endif /* CHAUFFAGE_PID_G_TEMPPID_H_ */
