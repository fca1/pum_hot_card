/*
 * temperature.c
 *
 *  Created on: 19 mars 2021
 *      Author: rapha
 */


#include <chauffage/hard/g_emule_i2c.h>
#include <chauffage/hard/g_hard.h>
#include <chauffage/hard/g_si7053.h>
#include <chauffage/misc/g_delay.h>
#include <stdint.h>




void sensorSI7053_reset(void)
{
i2c_write_byte(0x80,0xFE);
delay_ms(20);
}


int16_t sensorSI7053_read_decideg(void)
	{
	// double tt= 175.72*(tblR[0]*256.0+tblR[1])/65536.0-46.85;

	uint8_t tblR[2]= { };

	i2c_write_byte(0x80,0xF3);
	delay_ms(40);
	i2c_read_byte(0x80);
	i2c_read_bytes(0x80, sizeof(tblR), tblR);
	uint16_t raw = (tblR[0]<<8)+tblR[1];
	uint32_t tp= (17572L/2)*raw;
	tp/=32768L;
	tp-=4685;
	tp/=10;
	return (int16_t)tp;
	}


uint8_t * sensorSI7053_read_serial(uint64_t *p1)
{
uint8_t buf[8];
const uint8_t tbl[] = { 0xFA,0x0F };
i2c_write_bytes(0x80,sizeof(tbl),tbl);
i2c_read_bytes(0x80, sizeof(buf), buf);
uint8_t buf1[6];
const uint8_t tbl1[] = { 0xFC,0xC9 };
i2c_write_bytes(0x80,sizeof(tbl1),tbl1);
i2c_read_bytes(0x80, sizeof(buf1), buf1);
uint8_t * ptr = (uint8_t*)p1;
ptr[7] = buf[0];
ptr[6] = buf[2];
ptr[5] = buf[4];
ptr[4] = buf[6];
ptr[3] = buf1[0];
ptr[2] = buf1[1];
ptr[1] = buf1[2];
ptr[0] = buf1[3];
return ptr;

}
