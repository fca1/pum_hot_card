#include <chauffage/automaton/g_automger.h>


extern void task_init_hard(void);
extern uint8_t ts_smart_tick_automaton(void);


extern void TIMER_D(t_task_timer_cnt time,e_auto_evt evt,t_auto_data data);
extern void PUSH(e_auto_evt evt);
extern void PUSH_D(e_auto_evt evt,t_auto_data data);
extern void TIMER(t_task_timer_cnt time,e_auto_evt evt);


