#include <chauffage/automaton/g_automger.h>
#include <chauffage/automaton/g_timerTask.h>
#include <stdio.h>




const t_automaton_state *auto_motor_event_state(const t_automaton_state *ptr,t_type_event event)
{
const t_automaton_state *current_state=ptr;  
while(ptr->fcnt_automaton)
    {
    if (ptr->event.stv.evt==event.stv.evt)
      {
      ptr->fcnt_automaton(event);  
      if (ptr->nextState)
        {
        current_state =ptr->nextState; 
        }
      return current_state;
      
      }
    ptr++;
    }  
return NULL;
}




uint8_t auto_motor_event(t_automaton_ctxt *ctxt)
{
uint8_t cntEvent=0;  
while (ctxt->index_read!=ctxt->index_write) 
  {
  cntEvent++;  
  t_type_event event =  ctxt->events[ctxt->index_read]; 
  ctxt->index_read = (ctxt->index_read+1)%SIZE_QUEUE_AUTOMATON;
  const t_automaton_state *ptr = auto_motor_event_state(ctxt->currentState,event);
  if (!ptr && ctxt->fcnt_hook_not_found )
    {
    // Chercher dans l'�tat hook si evenement attendu.
    ptr = auto_motor_event_state(ctxt->hookState,event);
    if (!ptr)
      {
      // evenement non trouve, gestion a part.   
      ptr = ctxt->fcnt_hook_not_found(ctxt->currentState,event);
      }
    if (ptr && (ptr != ctxt->hookState))
      {
      ctxt->currentState = ptr;   
      }
    }
  else
    {
    ctxt->currentState = ptr;  
    }
  }
return cntEvent;
}

/**
* Permet de faire un changement dans la file d'attente (en remplacant les evenements)
*/

uint8_t auto_replace_event_in_waiting_stream(t_automaton_ctxt *ctxt,t_type_event event_to_replace,t_type_event event)
{
uint8_t nber_event_replaced=0;  
uint8_t ir= ctxt->index_read;  
while (ir!=ctxt->index_write) 
  {
  t_type_event evtR =  ctxt->events[ctxt->index_read]; 
  if (evtR.stv.evt == event_to_replace.stv.evt)
    {
    nber_event_replaced++;  
    evtR = event;
    }
  ir = (ir+1)%SIZE_QUEUE_AUTOMATON;
  }
return nber_event_replaced;
}



void auto_init(t_automaton_ctxt *ctxt,const t_automaton_state * const initState,t_fcnt_hook fcnt_hook_not_found,const t_automaton_state * const hookState)
{
ctxt->index_read=ctxt->index_write = 0;
ctxt->currentState = initState;
ctxt->fcnt_hook_not_found = fcnt_hook_not_found;
ctxt->hookState = hookState;
}

uint8_t auto_push_event(t_automaton_ctxt *ctxt,t_type_event event)
{
uint8_t w =((ctxt->index_write+1)%SIZE_QUEUE_AUTOMATON);
if (w==ctxt->index_read) 
  {
  return 0;
  }
ctxt->events[ctxt->index_write] = event;
ctxt->index_write = w;
return 1;
}



