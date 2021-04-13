/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F107DE.DVF                                                     */
/*    V1.21 (2013/07/30)                                                */
/*    Copyright(C) 2013 Renesas                                         */
/* Tool Version: 4.0.0                                                  */
/* Date Generated: 2020/01/17                                           */
/************************************************************************/
#ifndef INTERRUPT_HANDLERS_H
#define INTERRUPT_HANDLERS_H

/*
 * INT_WDTI (0x4)
 */
void INT_WDTI(void) __attribute__ ((interrupt));

/*
 * INT_LVI (0x6)
 */
void INT_LVI(void) __attribute__ ((interrupt));

/*
 * INT_P0 (0x8)
 */
void INT_P0(void) __attribute__ ((interrupt));

/*
 * INT_P3 (0xE)
 */
void INT_P3(void) __attribute__ ((interrupt));

/*
 * INT_P4 (0x10)
 */
void INT_P4(void) __attribute__ ((interrupt));

/*
 * INT_DMA0 (0x1A)
 */
void INT_DMA0(void) __attribute__ ((interrupt));

/*
 * INT_DMA1 (0x1C)
 */
void INT_DMA1(void) __attribute__ ((interrupt));

/*
 * INT_CSI00/INT_ST0 (0x1E)
 */
void INT_ST0(void) __attribute__ ((interrupt));
//void INT_CSI00(void) __attribute__ ((interrupt));

/*
 * INT_SR0 (0x20)
 */
void INT_SR0(void) __attribute__ ((interrupt));

/*
 * INT_SRE0/INT_TM01H (0x22)
 */
void INT_TM01H(void) __attribute__ ((interrupt));
//void INT_SRE0(void) __attribute__ ((interrupt));

/*
 * INT_ST1 (0x24)
 */
void INT_ST1(void) __attribute__ ((interrupt));

/*
 * INT_SR1 (0x26)
 */
void INT_SR1(void) __attribute__ ((interrupt));

/*
 * INT_SRE1/INT_TM03H (0x28)
 */
void INT_TM03H(void) __attribute__ ((interrupt));
//void INT_SRE1(void) __attribute__ ((interrupt));

/*
 * INT_IICA0 (0x2A)
 */
void INT_IICA0(void) __attribute__ ((interrupt));

/*
 * INT_TM00 (0x2C)
 */
void INT_TM00(void) __attribute__ ((interrupt));

/*
 * INT_TM01 (0x2E)
 */
void INT_TM01(void) __attribute__ ((interrupt));

/*
 * INT_TM02 (0x30)
 */
void INT_TM02(void) __attribute__ ((interrupt));

/*
 * INT_TM03 (0x32)
 */
void INT_TM03(void) __attribute__ ((interrupt));

/*
 * INT_AD (0x34)
 */
void INT_AD(void) __attribute__ ((interrupt));

/*
 * INT_RTC (0x36)
 */
void INT_RTC(void) __attribute__ ((interrupt));

/*
 * INT_IT (0x38)
 */
void INT_IT(void) __attribute__ ((interrupt));

/*
 * INT_STDL4 (0x3C)
 */
void INT_STDL4(void) __attribute__ ((interrupt));

/*
 * INT_SRDL4/INT_SREDL4 (0x3E)
 */
void INT_SREDL4(void) __attribute__ ((interrupt));
//void INT_SRDL4(void) __attribute__ ((interrupt));

/*
 * INT_P20/INT_P22 (0x40)
 */
void INT_P22(void) __attribute__ ((interrupt));
//void INT_P20(void) __attribute__ ((interrupt));

/*
 * INT_TM04 (0x42)
 */
void INT_TM04(void) __attribute__ ((interrupt));

/*
 * INT_TM05 (0x44)
 */
void INT_TM05(void) __attribute__ ((interrupt));

/*
 * INT_TM06 (0x46)
 */
void INT_TM06(void) __attribute__ ((interrupt));

/*
 * INT_TM07 (0x48)
 */
void INT_TM07(void) __attribute__ ((interrupt));

/*
 * INT_CMP0 (0x4A)
 */
void INT_CMP0(void) __attribute__ ((interrupt));

/*
 * INT_CMP1 (0x4C)
 */
void INT_CMP1(void) __attribute__ ((interrupt));

/*
 * INT_CMP2 (0x4E)
 */
void INT_CMP2(void) __attribute__ ((interrupt));

/*
 * INT_CMP3/INT_P9 (0x50)
 */
void INT_P9(void) __attribute__ ((interrupt));
//void INT_CMP3(void) __attribute__ ((interrupt));

/*
 * INT_CMP4/INT_P10 (0x52)
 */
void INT_P10(void) __attribute__ ((interrupt));
//void INT_CMP4(void) __attribute__ ((interrupt));

/*
 * INT_CMP5/INT_P11 (0x54)
 */
void INT_P11(void) __attribute__ ((interrupt));
//void INT_CMP5(void) __attribute__ ((interrupt));

/*
 * INT_TMKB0 (0x56)
 */
void INT_TMKB0(void) __attribute__ ((interrupt));

/*
 * INT_TMKB1 (0x58)
 */
void INT_TMKB1(void) __attribute__ ((interrupt));

/*
 * INT_TMKB2 (0x5A)
 */
void INT_TMKB2(void) __attribute__ ((interrupt));

/*
 * INT_TMKC0 (0x5C)
 */
void INT_TMKC0(void) __attribute__ ((interrupt));

/*
 * INT_MD (0x5E)
 */
void INT_MD(void) __attribute__ ((interrupt));

/*
 * INT_P21/INT_P23 (0x60)
 */
void INT_P23(void) __attribute__ ((interrupt));
//void INT_P21(void) __attribute__ ((interrupt));

/*
 * INT_FL (0x62)
 */
void INT_FL(void) __attribute__ ((interrupt));

/*
 * INT_BRK_I (0x7E)
 */
void INT_BRK_I(void) __attribute__ ((interrupt));

//Hardware Vectors
//PowerON_Reset (0x0)
void PowerON_Reset(void) __attribute__ ((interrupt));
#endif
