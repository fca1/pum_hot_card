
// Wrappe le systeme de timer (qui est une queue de timer se d�clenchant lorsque le timer est termin�,
// Au gestionnaire automate (automate � �tat fini) permettant de disposer � la fois d'un moteur automaton (permettant d'appeler des fonctions sur evenements et garder un etat) 
// avec le gestion timer existante. 




#include <chauffage/automaton/g_timerTask.h>
#include <chauffage/automaton/g_wrapperAutomatonTimer.h>
#include <stdio.h>




static t_type_event evt_filter;  // Utilise dans le cadre simple du timer


static void fcntTaskTimerAutomaton(t_timer_param param)
{
if (!auto_push_event(&ctxt_auto,*((t_type_event *)&param)))
  {
  asm("nop");  
  }
}
/**
* Cette fonction n'est utilis�e que par l'automate en interne (sert de wrapper entre les eveenements de type automate et ceux de timer)
* @return true si l'evenement de type t_timer_param.evt sont les memes que celui du filtre. 
**/
static uint8_t fcntFilterAutomaton(t_timer_param param)
{
return  ((t_type_event *)&param)->stv.evt == evt_filter.stv.evt;
}



/**
* @param event evenement de type timer a chercher (doit etre en cours) 
* @return false si le timer n'existe pas (ce qui ne veut pas dire que l'evenement n'est pas dans la liste des events en attente) 
*
*/ 
uint8_t wauto_is_timer_event_running(t_event event)
{
evt_filter.stv.evt  = event;  
return  timerIsRunning(fcntTaskTimerAutomaton,fcntFilterAutomaton);
}

/**
* Recherche dans la queue des evenements si l'evenement timer est pr�sent, le retire.
* Supprime �galement tous les timers en cours qui fourniront cet evenement. 
* @param event supprime l'�venement des timers et de la file d'evenements en attente. 
* @return Le nombre de timers supprim�s avec cet �venement. 
*/
uint8_t wauto_remove_timer(t_event event)
{
// Suppression de l'evenement du timer et de la file d'attente.   
static const t_type_event none={ .stv.evt=EVT_NONE };
t_type_event evt={ .stv.evt=event };
auto_replace_event_in_waiting_stream(&ctxt_auto,evt,none);  
evt_filter.stv.evt  = event;  
return timerTaskRemoveTasks(fcntTaskTimerAutomaton,fcntFilterAutomaton);
}

/**
* Lance un timer (reamorcable ou non) qui a l'issue produira l'evenement @see event avec la data associ�e. 
* @warning il n'est pas possible de lancer 2 timers avec le m�me evenement, il y aura suppression de celui en cours. 
* @param time temps en ticks du timer avant d'ecrire l'evenement dans la file d'attente. 
* @param event valeur de l'evenement � l'issue du timer
* @param data associ�e � l'evenement.
* @param timeRepeat si diff�rent de 0, temps de r�p�tition perpetuel du timer. 
**/
uint8_t wauto_start_timer(t_task_timer_cnt time,t_event event,t_auto_data data, t_task_timer_cnt timeRepeat)
{
t_type_event temp; temp.stv.evt=event; temp.stv.data=data;  
wauto_remove_timer(event);  // IL n'y a qu'un seul timer 
return timerTaskPostTask(time,fcntTaskTimerAutomaton,timeRepeat,temp.param);  
}


/**
* Cette fonction est appel�e par le moteur de l'automate, inscrit lors de l'initialisation de l'automate (contexte) 
* Fonction exemple par d�faut d'un probleme issue de l'automate. Si l'evenement n'est pas trouv� dans l'�tat courant et l'etat par defaut, 
* il y a blocage pour permettre le debug. 
* @param state �tat courant de l'automate
* @param event event non trouv� dans l'�tat courant et l'�tat par d�faut de l'automate. 
* @return NULL pour rester dans l'�tat courant, ou valeur d'un nouvel �tat (forcage)
*/  
const t_automaton_state * wauto_auto_hook(const t_automaton_state *state,t_type_event event)
{
asm("nop");
#ifdef DEBUG_SPEEDUP
while(event.stv.evt);
#endif
return NULL;
}
