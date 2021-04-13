// Version V0 creation 
// Version V1.1 optimisation gestion par liste permettant de gagner N*


/**
*  define a 1 si tick est appel� via une interruption. (obligatoire)
* @see timerTask_tick 
*/
#define CALL_TICK_INTERRUPT 0
#define CALL_TICK_REENTRANT 0
#define PROOF_MAX_TIMER     1

#include <chauffage/automaton/g_timerTask.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


typedef uint8_t bool;

#ifdef DEBUG
#else
// Supress Assert 
#define NDEBUG
#define PRINTF_DEBUG(...)
#endif

#if PROOF_MAX_TIMER
uint8_t stat_proof_max;
#endif


#define DEBUG_OPTION  (0&DEBUG)



#include <chauffage/automaton/g_timerTask.h>
#include <string.h>
#include <stdio.h>






static void fcntSortTimes(uint8_t index);
static void fcntDeleteTime(uint8_t index);




static t_task_timer listTaskTimer[NBER_TIMERS_IN_SAME_TIME];
static t_task_timer *tblSort[NBER_TIMERS_IN_SAME_TIME];





static void fcntDeleteTime(uint8_t index)
{
if (tblSort[index+1])
  {
  // Rajouter le temps � celui supprim�  
  tblSort[index+1]->timerUnit_ms+=tblSort[index]->timerUnit_ms;
  }
tblSort[index]->fcnt = NULL;
tblSort[NBER_TIMERS_IN_SAME_TIME-1]=NULL;
// Scroll
memmove(&tblSort[index],&tblSort[index+1],sizeof(tblSort[0])*(NBER_TIMERS_IN_SAME_TIME-index-1));  
}



static void fcntSortTimes(uint8_t index)
{
// Parcourir la liste et retrancher le temps avant insertion
for (uint8_t i=0;i<index;i++)
    {
    if ( tblSort[i])
      {
      if( tblSort[index]->timerUnit_ms > tblSort[i]->timerUnit_ms)
        {
        tblSort[index]->timerUnit_ms-=tblSort[i]->timerUnit_ms;
        }
      else
        {
        // L'emplacement est trouv� 
        tblSort[i]->timerUnit_ms -= tblSort[index]->timerUnit_ms;
        // Index s'insere � la place de i
        memmove(&tblSort[i+1],&tblSort[i],sizeof(tblSort[0])*(NBER_TIMERS_IN_SAME_TIME-i-1));  
        tblSort[i] = tblSort[index+1]; // index+1 car il a ete egalement boug�.
        tblSort[index+1] = NULL;
        return;
        }
      }
    else
      {
      tblSort[i] = tblSort[index];
      tblSort[index] = 0;
      return;
      }
    }
}
  
  
  



bool timerTaskRestart(t_task_timer_cnt time,t_ptrFcntVoidTaskTimer fcntTaskTimer,t_task_timer_cnt timeRepeat,t_timer_param param)
{
timerTaskRemoveTasks(fcntTaskTimer,NULL);
return timerTaskPostTask(time,fcntTaskTimer,timeRepeat,param);
}


bool timerIsRunning(t_ptrFcntVoidTaskTimer fcntTaskTimer,t_ptrFnctUint8TaskTimer fcntFilterTimer)
{
  for (uint8_t i=0;i<NBER_TIMERS_IN_SAME_TIME;i++)
    {
    if (tblSort[i]==NULL) return 0; // La liste est deja parcourue.  
    if ((tblSort[i]->fcnt==fcntTaskTimer))
        {
        if (fcntFilterTimer)
          {
          if (fcntFilterTimer(tblSort[i]->param))
            return 1;
          }
        else
          {
          return 1;
          }
        }
    }
return 0;
}


uint8_t timerTaskRemoveTasks(t_ptrFcntVoidTaskTimer fcntTaskTimer,t_ptrFnctUint8TaskTimer fcntFilterTimer)
{
uint8_t found = 0;  
for (uint8_t i=0;i<NBER_TIMERS_IN_SAME_TIME;i++)
  {
  if (tblSort[i]==NULL) break; // La liste est deja parcourue.  
  if (((tblSort[i]->fcnt==fcntTaskTimer))|| (fcntTaskTimer==NULL))
      {
      bool suppress = 1;   
      if (fcntFilterTimer)
        {
        suppress = fcntFilterTimer(tblSort[i]->param);
        }
      if (suppress || (fcntTaskTimer==NULL))
        {
        // Remettre le temps a 0
        fcntDeleteTime(i);
        found += 1;
        i=i-1;
        }
      }
  }
return found;
}




bool timerTaskPostTask(t_task_timer_cnt time,t_ptrFcntVoidTaskTimer fcntTaskTimer,t_task_timer_cnt timeRepeat,t_timer_param param)
{
PRINTF_DEBUG("timerTaskPostTask(%d , %x)\n",
       (uint16_t)time,
       fcntTaskTimer);
for (uint8_t i=0;i<NBER_TIMERS_IN_SAME_TIME;i++)
  {
  if (tblSort[i]==NULL)
    {
    for (uint8_t j=0;j<NBER_TIMERS_IN_SAME_TIME;j++)  
      {
      if (listTaskTimer[j].fcnt == NULL)   
        {
        tblSort[i] =   &listTaskTimer[j];
        break;
        }
      }
    if (tblSort[i] == NULL) return 0; // plus de place.   
    // une place a ete trouv�e
    tblSort[i]->timerUnit_ms                 = time;
    tblSort[i]->fcnt                           = fcntTaskTimer;
    tblSort[i]->cycleRepeat_timerUnit_ms     = timeRepeat; 
    tblSort[i]->param                        = param;
    fcntSortTimes(i);
#if PROOF_MAX_TIMER
    if (stat_proof_max<i) stat_proof_max=i;
#endif

    return 1;
    }
  }
return 0;
}

void timerTaskClearAll(void)
{
timerTaskInit();  
}



void timerTaskInit(void)
{
#if PROOF_MAX_TIMER
stat_proof_max=0;
#endif
  
for (uint8_t i=0;i<NBER_TIMERS_IN_SAME_TIME;i++)
  {
  tblSort[i] = NULL;
  listTaskTimer[i].fcnt = NULL; // indique le timer est libre.
  }
}


void timerTask_tick(void)
{
// Parcourir toute la liste  
if (tblSort[0])
  {
  if (tblSort[0]->timerUnit_ms)
  	  {
	  tblSort[0]->timerUnit_ms--;
  	  }
  }
while(tblSort[0])
  {
      if (!tblSort[0]->timerUnit_ms)
        {
        t_task_timer tmp =   *tblSort[0];
        fcntDeleteTime(0);
        // Le timer a echu.
        if (tmp.cycleRepeat_timerUnit_ms)
          {
          // Il s'agit d'un timer avec restart automatique
          timerTaskPostTask(tmp.cycleRepeat_timerUnit_ms,tmp.fcnt,tmp.cycleRepeat_timerUnit_ms,tmp.param);
          }
        // La fonction existe est est appelee. Attention a ne pas avoir de delay a l'interieur. 
        tmp.fcnt(tmp.param);
        PRINTF_DEBUG("call timerTask(%x)\n",tmp.fcnt);
        }
  else
    {
    return;
    }
  }
}


#if DEBUG
static void fcntTest1(void);
static void fcntTest2(void);
static void fcntTest3(void);
static void fcntTest4(void);
static void fcntTest5(void);

static void fcntTest1(void){}
static void fcntTest2(void){}
static void fcntTest3(void){}
static void fcntTest4(void){}
static void fcntTest5(void){}
#endif 



void unitTestTimer(void)
{
#if DEBUG
timerTaskInit();  
assert(timerTaskRemoveTasks(fcntTest1)==0);
bool result = timerTaskPostTask(1,fcntTest1,1,0);
assert(result);
result = timerTaskRemoveTasks(fcntTest1);
assert(result);
result = timerTaskPostTask(1,fcntTest1,0,0);
assert(result);
result = timerIsRunning(fcntTest1);
assert(result);
timerTask_tick();
result = timerIsRunning(fcntTest1);
assert(result==0);
result = timerTaskPostTask(1,fcntTest1,0,0);
result = timerTaskPostTask(1,fcntTest2,0,0);
result = timerTaskPostTask(1,fcntTest3,0,0);
assert(result);
// Les 3 timers doivent etre supprimes d'un coup.
timerTask_tick();
result = timerIsRunning(fcntTest3);
assert(result==0);
// Insertion dans un ordre different des temps 
result = timerTaskPostTask(3,fcntTest1,0,0);
result = timerTaskPostTask(1,fcntTest2,0,0);
result = timerTaskPostTask(2,fcntTest3,0,0);
result = timerTaskPostTask(3,fcntTest4,0,0);
timerTask_tick();
result = timerIsRunning(fcntTest2);
assert(result==0);
result = timerIsRunning(fcntTest3);
assert(result);
result = timerIsRunning(fcntTest4);
assert(result);
result = timerIsRunning(fcntTest1);
assert(result);
timerTask_tick();
result = timerIsRunning(fcntTest3);
assert(result==0);
result = timerIsRunning(fcntTest4);
assert(result);
result = timerIsRunning(fcntTest1);
assert(result);
timerTask_tick();
result = timerIsRunning(fcntTest4);
assert(result==0);
result = timerIsRunning(fcntTest1);
assert(result==0);
// Test de la suppression en milieu de liste. 
timerTaskPostTask(3,fcntTest1,0);
timerTaskPostTask(1,fcntTest2,0);
timerTaskPostTask(2,fcntTest3,0);
result = timerTaskRemoveTasks(fcntTest3);
result = timerIsRunning(fcntTest3);
assert(result==0);
result = timerIsRunning(fcntTest1);
assert(result);
result = timerIsRunning(fcntTest2);
assert(result);
#endif
}
