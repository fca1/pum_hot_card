#pragma once
#include <chauffage/automaton/t_timerTask.h>
#include <chauffage/t_auto_evt.h>
#include <stdint.h>

#define SIZE_QUEUE_AUTOMATON   10


// Warning, les types d'evenements sont d�finis avant 
// ------------------------------------------------
typedef e_auto_evt t_event;      
typedef uint16_t   t_auto_data;
// ------------------------------------------------


#pragma pack(1)

struct t_stv
  {
  t_event               evt;
  t_auto_data           data;
  };


typedef union
{
t_timer_param    param;
struct t_stv     stv;
} t_type_event;


typedef void (*t_fcnt_automaton)(t_type_event);



typedef struct _t_automaton_state
{
const t_type_event                          event;
const t_fcnt_automaton                      fcnt_automaton;  
const struct _t_automaton_state             *  nextState;
} t_automaton_state;


typedef  struct _t_automaton_ctxt  t_automaton_ctxt;
typedef const t_automaton_state    * (*t_fcnt_hook)(const t_automaton_state *state,t_type_event);


struct _t_automaton_ctxt
{
const t_automaton_state               *currentState;
t_type_event                    events[SIZE_QUEUE_AUTOMATON];
uint8_t                         index_read;
uint8_t                         index_write;
const t_automaton_state               *hookState;
t_fcnt_hook                     fcnt_hook_not_found;
};

#pragma pack()
