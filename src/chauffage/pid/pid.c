/*
 * pid.c
 *
 *  Created on: 7 nov. 2019
 *      Author: frant
 */


#include <chauffage/pid/g_pid.h>
#include <string.h>
#include <stdint.h>



static const struct t_pid pid_values_init =
{
.Kp =(uint32_t) ((1.0)*65536.0),
.Kd =(uint32_t) ((0.00)*65536.0),
.Ki =(uint32_t) ((0.01)*65536.0),
.consigne_deciDeg=200,							// Sortie = 20.0°C
};


struct t_pid pid_values;


static int32_t  error_previous=0;
static int32_t  error_sum=0;
static int32_t tbl_error_previous[8];
static uint8_t index_rw=0;
static int32_t result;
static int16_t  error;

static int32_t fcnt_error_previous(int32_t newValue)
{
result-=tbl_error_previous[index_rw];
result+=newValue;
tbl_error_previous[index_rw]=newValue;
index_rw++;
index_rw=index_rw%(sizeof(tbl_error_previous)/sizeof(tbl_error_previous[0]));
return result;
}

void pid_reset(const struct t_pid * p_init)
{
pid_values=*p_init;
pid_init();
}


void pid_init(void)
{
error_previous=0;
result=0;
error_previous=0;
memset(tbl_error_previous,0,sizeof(tbl_error_previous));

}

const int16_t pid_get_absolute_error(int16_t measured_deciDeg)
{
return 	pid_values.consigne_deciDeg-measured_deciDeg;
}



int16_t pid_compute(int16_t reference_deciDeg)
{
// Calcul PID
error = pid_get_absolute_error(reference_deciDeg);
error_sum=fcnt_error_previous(error_previous);
int32_t  error_delta = error-error_previous;

int32_t  pwm_change = pid_values.Kp*error;
pwm_change += pid_values.Ki * error_sum;
pwm_change += pid_values.Kd * error_delta;

error_previous = error;
int16_t te=(int16_t)(pwm_change/65536L);

return te;
}


const int16_t pid_get_error(void)
{
return error;
}


struct t_pid * pid_get_config(void)
{
return &pid_values;
}
