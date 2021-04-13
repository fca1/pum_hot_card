/*
 * g_emule_i2c.h
 *
 *  Created on: 9 mars 2017
 *      Author: fca
 */

#pragma once 

#include <stdint.h>

extern uint8_t  i2c_write_byte(const uint8_t adrC,const uint8_t val);
extern uint8_t  i2c_read_byte(const uint8_t adrC);
extern void i2c_write_bytes(const uint8_t adrC,uint32_t length,const  uint8_t *ptrBuf);
extern uint8_t * i2c_read_bytes(const uint8_t adrC,uint32_t length, uint8_t *ptrBuf);
extern void i2c_configure(void);








