/*
 * comm.c
 *
 *  Created on: 11 avr. 2021
 *      Author: frant
 */



#include "g_comm.h"
#include "g_my_main.h"
#include "g_delay.h"
#include <string.h>
#include "g_tempPid.h"
#include "r_cg_serial.h"


// Utilise par la liaison serie en reception.
struct t_rotary_byte buf_rcve_uart1;
struct t_rotary_byte buf_rcve_uart4;

// Timeout management
static volatile uint32_t save_tick_ms_1;
static volatile uint32_t save_tick_ms_4;
#define TMO_MS_INTER_CHAR		10


static struct t_comm_rcve rcve1;
static struct t_comm_rcve rcve4;
static struct t_comm_emit emit_buffer;

static uint8_t index1;
static uint8_t index4;



static uint8_t fcnt_compute_chk(uint8_t *ptrStart, uint8_t len)
{
uint8_t chk= 0;
while(len--)
	{
	chk+=*ptrStart;
	ptrStart++;
	}
return chk;

}


static void fill_serial1(void)
{
if (tick_1ms-save_tick_ms_1>TMO_MS_INTER_CHAR)		// TMO
	{
	index1=0;
	}
while(circularGetLen(&buf_rcve_uart1))
	{
	uint8_t *ptr1 = ((uint8_t*)(&rcve1));
	save_tick_ms_1 = tick_1ms;
	ptr1[index1++]=*circularPop(&buf_rcve_uart1);
	if (index1>=sizeof(rcve1)) index1--;
	}
}

static void fill_serial4(void)
{
if (tick_1ms-save_tick_ms_4>TMO_MS_INTER_CHAR)		// TMO
	{
	index4=0;
	}
while(circularGetLen(&buf_rcve_uart4))
	{
	uint8_t *ptr4 = ((uint8_t*)(&rcve4));
	save_tick_ms_4 = tick_1ms;
	ptr4[index4++]=*circularPop(&buf_rcve_uart4);
	if (index4>=sizeof(rcve4)) index4--;
	}
}




struct t_comm_rcve * compute_serial1(uint8_t *length)
{
fill_serial1();
uint8_t *ptr1 = ((uint8_t*)(&rcve1));
if ((rcve1.header.stx==STX) && index1>=sizeof(rcve1.header))
	{
	for (uint8_t i=0;i<index1;i++)
		{
		if ((ptr1[i]==ETX) && i+1<index1)
			{
			if (fcnt_compute_chk(ptr1,i+1)==ptr1[i+1])
				*length = i+1;
				return &rcve1;
			}
		}
	}
*length = 0;
return NULL;
}

struct t_comm_rcve* compute_serial4(uint8_t *length)
{
fill_serial4();
uint8_t *ptr4 = ((uint8_t*)(&rcve4));
if ((rcve4.header.stx==STX) && index4>=sizeof(rcve4.header))
	{
	for (uint8_t i=0;i<index4;i++)
		{
		if ((ptr4[i]==ETX) && i+1<index4)
			{
			if (fcnt_compute_chk(ptr4,i+1)==ptr4[i+1])
				*length = i+1;
				return &rcve4;
			}
		}
	}
*length = 0;
return NULL;
}


uint8_t  comm_build_msg_identity(struct t_comm_emit *ptrEmit,uint8_t identity,uint64_t unique)
{
	ptrEmit->header.stx = STX;
	ptrEmit->header.cmd = ASK_IDENTITY;
ptrEmit->header.adddr = identity;
ptrEmit->u.identity.identity = unique;
// Caster pour remplir la fin.
struct t_footer *ptr =(struct t_footer*) &ptrEmit->u.buffer[sizeof(ptrEmit->u.identity)];
uint8_t size =((uint8_t*)ptr)-((uint8_t*)ptrEmit)+sizeof(struct t_footer)-1;
ptr->etx = ETX;
ptr->chk = fcnt_compute_chk((uint8_t*)ptrEmit,size);
return size+1;
}

uint8_t comm_build_msg_status(struct t_comm_emit *ptrEmit, uint8_t identity,struct t_status *p)
{
ptrEmit->header.stx = STX;
ptrEmit->header.cmd = GET_STATUS;
ptrEmit->header.adddr = identity;
ptrEmit->u.status = *p;
// Caster pour remplir la fin.
struct t_footer *ptr =(struct t_footer*) &ptrEmit->u.buffer[sizeof(ptrEmit->u.status)];
uint8_t size =((uint8_t*)ptr)-((uint8_t*)ptrEmit)+sizeof(struct t_footer)-1;
ptr->etx = ETX;
ptr->chk = fcnt_compute_chk((uint8_t*)ptrEmit,size);
return size+1;
}




static void fcnt_refresh(void)
{

}


static void fcnt_emit(struct t_comm_emit *p,uint8_t serial,uint8_t length)
{
p->header.stx = STX;
p->header.adddr = identity;

if (serial==1)
	{
	R_UART1_Send((uint8_t*)p, length);
	}
else
	{
	R_UART4_Send((uint8_t*)p, length);
	}
}



static void fcnt_decode_msg(struct t_comm_rcve *p,uint8_t serial)
{
uint8_t length;
switch(p->header.cmd)
	{
	case	GET_STATUS:
		// Renvoie le status
		//emit_buffer = comm_build_msg_status(
		break;
	case ENABLE_HEAT:
		if (params.enabled)
			{
			status.actif = 1;
			}
		break;
	case SET_PARAMS:
		params = p->u.params;
		pid_refresh();
		break;
	case ASK_IDENTITY:
		// Renvoie l'identite.
		break;
	}


}



/**
 * Detecte si un messsage survient. Si c'est le cas, ou le destinataire est la carte et il est traité, sinon rcv1=>emit4 et rcv4=>emit1
 */
void comm_manage_serial(void)
{
struct t_comm_rcve *p;
uint8_t length;
p=compute_serial1(&length);
if (p->header.adddr==identity)
	{
	// C'est pour la carte, ne pas transmettre.
	fcnt_decode_msg(p,1);
	}
else
	{
	// renvoyer pour un autre
	while (!g_uart4_tx_cnt);
	R_UART4_Send((uint8_t*)p, length);
	}
p=compute_serial4(&length);
if (p->header.adddr==identity)
	{
	// C'est pour la carte, ne pas transmettre.
	fcnt_decode_msg(p,4);
	}
else
	{
	// renvoyer pour un autre
	while (!g_uart1_tx_cnt);
	R_UART1_Send((uint8_t*)p, length);
	}
}





