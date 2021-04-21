#ifndef __t_task_timer
#define __t_task_timer

#include "r_cg_macrodriver.h"
#include <stdint.h>


typedef uint64_t t_timer_param ;

typedef void (*t_ptrFcntVoidTaskTimer)(t_timer_param param);
typedef uint8_t (*t_ptrFnctUint8TaskTimer)(t_timer_param param);

typedef uint64_t        t_task_timer_cnt;

typedef struct st_task_timer
{
t_task_timer_cnt        timerUnit_ms;
t_task_timer_cnt        cycleRepeat_timerUnit_ms;     // Si different de 0, relance automatique. 
t_ptrFcntVoidTaskTimer  fcnt;
t_timer_param                param;
} t_task_timer;



#endif 
