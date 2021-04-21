//INTELLECTUAL AND INDUSTRIAL PROPERTY RIGHTS
//
// EPI ,E.U..R.L has the intellectual and industrial property rights of URL and source code, algorithm and binay.
// These rights protect graphic designs, source code, content and other elements of these code source,
// with the exception of property rights that are not owned by EPI and are owned by their respective owners.//
// EPI allows simple download and storage information of its depot in user's hard drive,
// but it is strictly prohibited to modify, distribute, reuse, or forward all or part of EPI's content
// for public or commercial purposes without EPIâ€™s written authorization.
//
// Actions that could infringe terms expressed above may constitute an infringement of the intellectual property
// protection rights in the consolidated text of the Intellectual Property Law (TRLPI),
// provoking lawsuits established in Articles to current Penal Code.

#include <chauffage/misc/g_misc.h>

volatile t_task_timer_cnt tick_1ms;

void delay_ms(t_task_timer_cnt delay_ms)
{
t_task_timer_cnt tick_1ms_save =tick_1ms;
// Attendre 5 secondes avant de recommencer
while (tick_1ms - tick_1ms_save < delay_ms)
	;
}
void delay_us(uint32_t delay_us)
{
while (delay_us--);

}

