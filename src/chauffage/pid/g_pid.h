/*
 * g_pid.h
 *
 *  Created on: 7 nov. 2019
 *      Author: frant
 */

#include <chauffage/pid/t_pid.h>
#include <stdint.h>

extern void pid_init(void);


extern int16_t pid_compute(int16_t reference_decideg);
extern const int16_t pid_get_error(void);
extern const int16_t pid_get_absolute_error(int16_t measured_decideg);
extern struct t_pid * pid_get_config(void);
extern void pid_reset(const struct t_pid * p_init);


extern struct t_pid pid_values;
