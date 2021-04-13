#pragma once



#include <chauffage/automaton/g_automger.h>


extern t_automaton_ctxt ctxt_auto;   // Contexte de l'automate. 


extern uint8_t wauto_is_timer_event_running(t_event event);
extern uint8_t wauto_remove_timer(t_event event);
extern uint8_t wauto_start_timer(t_task_timer_cnt time,t_event event,t_auto_data data, t_task_timer_cnt timeRepeat);
extern const t_automaton_state * wauto_auto_hook(const t_automaton_state *state,t_type_event event);


