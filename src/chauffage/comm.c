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
#define TMO_MS_INTER_CHAR		40


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
uint8_t *ptr1 = ((uint8_t*)(&rcve1));
while(circularGetLen(&buf_rcve_uart1))
	{
	save_tick_ms_1 = tick_1ms;
	ptr1[index1]=*circularPop(&buf_rcve_uart1);
	if (ptr1[index1]==3)
		{
		asm("nop");
		asm("nop");
		}


	if (index1<sizeof(rcve1)) index1++;
	}
}

static void fill_serial4(void)
{
if (tick_1ms-save_tick_ms_4>TMO_MS_INTER_CHAR)		// TMO
	{
	index4=0;
	}
uint8_t *ptr4 = ((uint8_t*)(&rcve4));
while(circularGetLen(&buf_rcve_uart4))
	{
	save_tick_ms_4 = tick_1ms;
	ptr4[index4]=*circularPop(&buf_rcve_uart4);
	if (index4<sizeof(rcve4)) index4++;
	}
}




struct t_comm_rcve * compute_serial1(uint8_t *length)
{
fill_serial1();
uint8_t *ptr1 = ((uint8_t*)(&rcve1));
if ((rcve1.header.stx==STX) && index1>=(sizeof(rcve1.header)+sizeof(rcve1.footer)))
	{
	for (uint8_t i=0;i<index1;i++)
		{
		if ((ptr1[i]==ETX) && i+1<index1)
			{
			if (fcnt_compute_chk(ptr1,i+1)==ptr1[i+1])
				{
				*length = index1;
				index1=0;
				return &rcve1;
				}
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
if ((rcve4.header.stx==STX) && index4>=(sizeof(rcve4.header)+sizeof(rcve4.footer)))
	{
	for (uint8_t i=0;i<index4;i++)
		{
		if ((ptr4[i]==ETX) && i+1<index4)
			{
			if (fcnt_compute_chk(ptr4,i+1)==ptr4[i+1])
				{
				*length = index4;
				index4=0;
				return &rcve4;
				}
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





static void fcnt_emit(struct t_comm_emit *p,uint8_t serial,uint8_t length)
{
p->header.stx = STX;
p->header.adddr = identity;

if (serial==1)
	{
	while (g_uart1_tx_cnt);
	R_UART1_Send((uint8_t*)p, length);
	}
else
	{
	while (g_uart4_tx_cnt);
	R_UART4_Send((uint8_t*)p, length);
	}
}



static uint8_t  fcnt_decode_msg(struct t_comm_rcve *p,uint8_t serial)
{
uint8_t length;
switch(p->header.cmd)
	{
	case	GET_STATUS:
		if (p->header.adddr!=identity && identity!=0xFF)
			return 0;
		// Renvoie le status
		length= comm_build_msg_status(&emit_buffer,identity,pid_refresh_status());
		fcnt_emit(&emit_buffer,serial,length);
		return 1;
	case ENABLE_HEAT:
		if (p->header.adddr!=identity && identity!=0xFF)
			return 0;
		if (params.enabled)
			{
			status.actif = p->u.enable.actif;
			}
		length= comm_build_msg_status(&emit_buffer,identity,pid_refresh_status());
		fcnt_emit(&emit_buffer,serial,length);
		return 1;
	case SET_PARAMS:
		if (p->header.adddr!=identity && identity!=0xFF)
			return 0;
		pid_refresh(&p->u.params);
		length= comm_build_msg_status(&emit_buffer,identity,pid_refresh_status());
		fcnt_emit(&emit_buffer,serial,length);
		return 1;
	case ASK_IDENTITY:
		// Renvoie l'identite. Si l'identite de cette carte est connue. Renvoyer l'identite.
		if (identity==0xFF && p->u.identity.identity!=unique_serial_nber)
			{
			// Cette carte ne connait pas son identite.
			if (p->header.adddr!=0xFF)
				{
				identity = p->header.adddr+1;		// L'identite vient d'etre determine.
				return 1;
				}
			}
		else
			{
			uint8_t l = comm_build_msg_identity(&emit_buffer, identity, unique_serial_nber);
			fcnt_emit(&emit_buffer,serial,l);
			return 1;
			}
	}
return 0;
}


void comm_flush1(void)
{

}
void comm_flush4(void)
{
while(circularGetLen(&buf_rcve_uart1))
	{
	circularPop(&buf_rcve_uart1);
	}
while(circularGetLen(&buf_rcve_uart4))
	{
	circularPop(&buf_rcve_uart4);
	}
}


/**
 * Detecte si un messsage survient. Si c'est le cas, ou le destinataire est la carte et il est traité, sinon rcv1=>emit4 et rcv4=>emit1
 */
void comm_manage_serial(void)
{
struct t_comm_rcve *p;
uint8_t length;
if (identity==0xff)
	{
	//# pas d'identite, demander l'identite
	struct t_comm_emit mm;
	uint8_t ll = comm_build_msg_identity(&mm, identity, unique_serial_nber);
	comm_flush1();
	comm_flush4();
	fcnt_emit(&mm,1,ll);
	fcnt_emit(&mm,4,ll);
	delay_ms(20);
	}

p=compute_serial1(&length);
if (p)
	{
	if (!fcnt_decode_msg(p,1))
		{
		// Si le distant a une adresse et que soit meme a une adresse, transferer le message.
		if ((p->header.adddr!=0xff) && identity!=0xFF)
			{
			while (g_uart4_tx_cnt);
			R_UART4_Send((uint8_t*)p, length);
			}
		}

	}
p=compute_serial4(&length);
if (p)
	{
	if (!fcnt_decode_msg(p,4))
		{
		// Si le distant a une adresse et que soit meme a une adresse, transferer le message.
		if ((p->header.adddr!=0xff) && identity!=0xFF)
			{
			while (g_uart1_tx_cnt);
			R_UART1_Send((uint8_t*)p, length);
			}
		}

	}

}





