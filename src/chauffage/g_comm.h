#include "l_comm.h"
#include "t_comm.h"
#include <chauffage/misc/g_circularByte.h>


extern struct t_rotary_byte buf_rcve_uart1;
extern struct t_rotary_byte buf_rcve_uart4;


extern void			comm_manage_serial(void);
struct t_comm_rcve* compute_serial1(uint8_t *length);
struct t_comm_rcve* compute_serial4(uint8_t *length);

extern uint8_t comm_build_msg_identity(struct t_comm_emit *ptrEmit,uint8_t identity,uint64_t unique);
extern uint8_t comm_build_msg_status(struct t_comm_emit *ptrEmit,uint8_t identity,struct t_status *p);





extern volatile uint16_t  g_uart1_tx_cnt;             /* uart1 transmit data number */
extern volatile uint16_t  g_uart4_tx_cnt;             /* uart4 transmit data number */
