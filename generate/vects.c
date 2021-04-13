/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F107DE.DVF                                                     */
/*    V1.21 (2013/07/30)                                                */
/*    Copyright(C) 2013 Renesas                                         */
/* Tool Version: 4.0.0                                                  */
/* Date Generated: 2020/01/17                                           */
/************************************************************************/
#include "interrupt_handlers.h"

extern void PowerON_Reset (void);

const unsigned char Option_Bytes[]  __attribute__ ((section (".option_bytes"))) = {
	0xef, 0xff, 0xe8, 0x85
};

const unsigned char Security_Id[]  __attribute__ ((section (".security_id"))) = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define VEC          __attribute__ ((section (".vec")))
const void *HardwareVectors[] VEC = {
	// Address 0x0
	PowerON_Reset,
	// Secure for Debugging
	(void*)0xFFFF
};

#define VECT_SECT          __attribute__ ((section (".vects")))
const void *Vectors[] VECT_SECT = {
	//INT_WDTI (0x4)
	INT_WDTI,
	//INT_LVI (0x6)
	INT_LVI,
	//INT_P0 (0x8)
	INT_P0,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	//INT_P3 (0xE)
	INT_P3,
	//INT_P4 (0x10)
	INT_P4,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	//INT_DMA0 (0x1A)
	INT_DMA0,
	//INT_DMA1 (0x1C)
	INT_DMA1,
	//INT_CSI00/INT_ST0 (0x1E)
	INT_ST0,
	//INT_SR0 (0x20)
	INT_SR0,
	//INT_SRE0/INT_TM01H (0x22)
	INT_TM01H,
	//INT_ST1 (0x24)
	INT_ST1,
	//INT_SR1 (0x26)
	INT_SR1,
	//INT_SRE1/INT_TM03H (0x28)
	INT_TM03H,
	//INT_IICA0 (0x2A)
	INT_IICA0,
	//INT_TM00 (0x2C)
	INT_TM00,
	//INT_TM01 (0x2E)
	INT_TM01,
	//INT_TM02 (0x30)
	INT_TM02,
	//INT_TM03 (0x32)
	INT_TM03,
	//INT_AD (0x34)
	INT_AD,
	//INT_RTC (0x36)
	INT_RTC,
	//INT_IT (0x38)
	INT_IT,
	// Padding
	(void*)0xFFFF,
	//INT_STDL4 (0x3C)
	INT_STDL4,
	//INT_SRDL4/INT_SREDL4 (0x3E)
	INT_SREDL4,
	//INT_P20/INT_P22 (0x40)
	INT_P22,
	//INT_TM04 (0x42)
	INT_TM04,
	//INT_TM05 (0x44)
	INT_TM05,
	//INT_TM06 (0x46)
	INT_TM06,
	//INT_TM07 (0x48)
	INT_TM07,
	//INT_CMP0 (0x4A)
	INT_CMP0,
	//INT_CMP1 (0x4C)
	INT_CMP1,
	//INT_CMP2 (0x4E)
	INT_CMP2,
	//INT_CMP3/INT_P9 (0x50)
	INT_P9,
	//INT_CMP4/INT_P10 (0x52)
	INT_P10,
	//INT_CMP5/INT_P11 (0x54)
	INT_P11,
	//INT_TMKB0 (0x56)
	INT_TMKB0,
	//INT_TMKB1 (0x58)
	INT_TMKB1,
	//INT_TMKB2 (0x5A)
	INT_TMKB2,
	//INT_TMKC0 (0x5C)
	INT_TMKC0,
	//INT_MD (0x5E)
	INT_MD,
	//INT_P21/INT_P23 (0x60)
	INT_P23,
	//INT_FL (0x62)
	INT_FL,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	//INT_BRK_I (0x7E)
	INT_BRK_I,
};

