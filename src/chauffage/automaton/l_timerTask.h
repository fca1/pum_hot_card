#ifndef __l_task_timer
#define __l_task_timer




#define NBER_TIMERS_IN_SAME_TIME                   16
#define TICK_TASK_TIMER_MS                         1
#define CVRT_TASK_TIMER_MS(x)                        ((t_task_timer_cnt)((x)/TICK_TASK_TIMER_MS))


#define DI_TICK() DI()
#define EI_TICK() EI()


#endif 
