/*
 * emule_i2c.c
 *
 *  Created on: 9 mars 2017
 *      Author: fca
 */



/*
 * tas5766m_i2c.c
 *
 *  Created on: 19 avr. 2015
 *      Author: fca
 */

#if 1

#include <chauffage/hard/l_hardPin.h>

#include <chauffage/hard/g_emule_i2c.h>
#include<stdint.h>


#define SCL_OUT()						SOFT_DIR_SCL(0)
#define SDA_OUT()						SOFT_DIR_SDA(0)
#define SDA_IN()						SOFT_DIR_SDA(1)
#define SCL_IN()						SOFT_DIR_SCL(1)

#define SDA(e)							SOFT_SDA(e)
#define SCL(e)							SOFT_SCL(e)
#define READ_SDA						SOFT_READ_SDA()

static void fcnt_delay(void)
{
for(volatile uint32_t x=0;x<10;x++)
	{

	}
}


static void fcnt_IIC_Init(void) //IIC Initial
{
SCL_OUT();
SDA_OUT();
SDA(1);
SCL(1);

}

static void fcnt_IIC_Start(void) //IIC Start Condition
{
	SDA_OUT();
    SCL_OUT();
	SDA(1);
	SCL(1);
	fcnt_delay();
	SDA(0);//START:when CLK is high,DATA change from high to low
	fcnt_delay();
	SCL(0);
}
static void fcnt_IIC_Stop(void) //IIC Stop Condition
{
	SDA(0); //STOP:when CLK is high DATA change from low to high
	SDA_OUT();
	SCL(0);
	fcnt_delay();
	SCL(1);
	SDA(1);
	SDA_IN();
        SCL_IN();
	fcnt_delay();
}
static uint8_t  fcnt_IIC_Wait_Ack(void) //ACK
{
	uint8_t  ucErrTime=0;
	SDA_IN();
	SDA(1);
	fcnt_delay();
	SCL(1);
	fcnt_delay();

	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			fcnt_IIC_Stop();
			return 1;
		}
	}
	SCL(0);
	return 0;
}
static void fcnt_IIC_Ack(void) //ACK
{
	SCL(0);
	SDA(0);
	SDA_OUT();
	fcnt_delay();
	SCL(1);
	fcnt_delay();
	SCL(0);
}
static void fcnt_IIC_NAck(void) //NACK
{
	SCL(0);
	SDA(1);
	SDA_OUT();
	fcnt_delay();
	SCL(1);
	fcnt_delay();
	SCL(0);
	fcnt_delay();
}
static void fcnt_IIC_Send_Byte(uint8_t  txd) //IIC Write Condition
{
	uint8_t  t;
	SDA_OUT();
	SCL(0);
	for(t=0;t<8;t++)
	{
		SDA((txd&0x80)>>7);
		txd<<=1;
		fcnt_delay();
		SCL(1);
		fcnt_delay();
		SCL(0);
		fcnt_delay();
	}
}
static uint8_t  fcnt_IIC_Read_Byte(unsigned char ack) //IIC Read Condition
{
	unsigned char i,receive=0;
	SDA_IN();

	for(i=0;i<8;i++ )
	{
		SCL(0);
		fcnt_delay();
		SCL(1);
		receive<<=1;
		if(READ_SDA)receive++;
		fcnt_delay();
	}
	if (!ack)
		fcnt_IIC_NAck();
	else
		fcnt_IIC_Ack();

	return receive;
}

void IIC_Restart(void) //ACK
{
SCL(1);
fcnt_IIC_Start();
}




uint8_t i2c_write_byte(const uint8_t adrC,const uint8_t val)
{
fcnt_IIC_Start();
fcnt_IIC_Send_Byte(adrC | 0);	// Write
if (fcnt_IIC_Wait_Ack()) return 1;
fcnt_IIC_Send_Byte((uint8_t)val);
fcnt_IIC_Wait_Ack();
fcnt_IIC_Stop();
return 1;
}


uint8_t  i2c_read_byte(const uint8_t adrC)
{
uint8_t val;
fcnt_IIC_Start();
fcnt_IIC_Send_Byte(adrC | 1);
fcnt_IIC_Wait_Ack();
val = fcnt_IIC_Read_Byte(0);
fcnt_IIC_Stop();
return val;
}


void i2c_write_bytes(const uint8_t adrC,uint32_t length,const  uint8_t *ptrBuf)
{
fcnt_IIC_Start();
fcnt_IIC_Send_Byte(adrC | 0);	// Write
if (fcnt_IIC_Wait_Ack()) return;
while(length--)
	{
	fcnt_IIC_Send_Byte((uint8_t)*ptrBuf);
	ptrBuf++;
	fcnt_IIC_Wait_Ack();
	}
fcnt_IIC_Stop();
}

uint8_t * i2c_read_bytes(const uint8_t adrC,uint32_t length, uint8_t *ptrBuf)
{

fcnt_IIC_Start();
fcnt_IIC_Send_Byte(adrC | 1);
fcnt_IIC_Wait_Ack();
uint8_t *ptr = ptrBuf;
do
	{
	*ptr =fcnt_IIC_Read_Byte(length!=1);	// Read
	ptr++;
	}
while(--length);
fcnt_IIC_Stop();
return ptrBuf;
}


void i2c_configure(void)
{
fcnt_IIC_Init();
fcnt_IIC_Stop();
}




#endif
