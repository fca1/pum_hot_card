


#include <chauffage/automaton/l_timerTask.h>
#include <chauffage/automaton/t_timerTask.h>


/**
* @param time temps avant l'appel de la callback 
* @param fcntTaskTimer fonction de callaback appelee apres que la tempo soit echue. 
* @param timeRepeat    fonction avec relance de la tempo apres appel de la fcntTaskTimer (eternel) sauf si 0
* @param param         la fonction callback est appele avec le parametre param
* @return true si le timer a bien ete poste, 0 si plus de place. 
* @warning si time=0, la fonction est appel�e imm�diatement. 
*/ 
extern uint8_t timerTaskPostTask(t_task_timer_cnt time,t_ptrFcntVoidTaskTimer fcntTaskTimer,t_task_timer_cnt timeRepeat,t_timer_param param);
extern void timerTaskClearAll(void);
/**
* Doit etre appele � @see TICK_TASK_TIMER_MS afin de faire progresser les timers.  
*/ 
extern void timerTask_tick(void);
/**
* Appele lors de l'init avant le 1er appel de @see timerTask_tick()
*/
extern void timerTaskInit(void);

/**
* Retire tous les timers en attente avec cette fonctionTask. 
* @param fcntFilterTimer si la fonction return true, alors la fonction est effectivement supprimée. NULL = pas de filtre 
* return Nombre de timers effectivement supprimes
*/

extern uint8_t timerTaskRemoveTasks(t_ptrFcntVoidTaskTimer fcntTaskTimer,t_ptrFnctUint8TaskTimer fcntFilterTimer);

/**
* Supprime tous les timers possedant la meme callback et relance un nouveau timer. 
*/

extern uint8_t timerTaskRestart(t_task_timer_cnt time,t_ptrFcntVoidTaskTimer fcntTaskTimer,t_task_timer_cnt timeRepeat,t_timer_param param);

/**
* @param fcntFilterTimer si la fonction return true, alors la fonction est effectivement supprimée. NULL = pas de filtre 
* @return true si le timer est en route
*/

extern uint8_t timerIsRunning(t_ptrFcntVoidTaskTimer fcntTaskTimer,t_ptrFnctUint8TaskTimer fcntFilterTimer);


/**
* Unit test (pour debug)
*/ 
extern void unitTestTimer(void);
