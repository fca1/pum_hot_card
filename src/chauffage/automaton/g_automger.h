#include <chauffage/automaton/t_automger.h>


extern uint8_t auto_motor_event(t_automaton_ctxt *ctxt);
extern const t_automaton_state *auto_motor_event_state(const t_automaton_state *state,t_type_event event);

extern void auto_init(t_automaton_ctxt *ctxt,const t_automaton_state * const initState,t_fcnt_hook  fcnt_hook_not_found,const t_automaton_state * const hookState);
extern uint8_t auto_push_event(t_automaton_ctxt *ctxt,t_type_event event);
extern uint8_t auto_replace_event_in_waiting_stream(t_automaton_ctxt *ctxt,t_type_event event_to_replace,t_type_event event);
