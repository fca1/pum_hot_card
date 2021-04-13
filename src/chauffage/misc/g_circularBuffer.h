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

#include <chauffage/misc/t_circularBuffer.h>
extern uint8_t circularPushBuffer(struct t_rotary_buffer *ptrBuffer, uint8_t *obj);
extern int8_t circularGetLenBuffer(const struct t_rotary_buffer *ptrBuffer);
extern uint8_t *circularPopBuffer(struct t_rotary_buffer *ptrBuffer);
extern void circularInitBuffer(struct t_rotary_buffer *ptrBuffer);

