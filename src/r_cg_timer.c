/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2018 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_timer.c
* Version      : CodeGenerator for RL78/I1A V2.04.03.01 [28 Oct 2018]
* Device(s)    : R5F107DE
* Tool-Chain   : GCCRL78
* Description  : This file implements device driver for TAU module.
* Creation Date: 11/04/2021
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TMR_KB_Create
* Description  : This function initializes the TMKB module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KB_Create(void)
{
    TKB0EN = 1U;    /* supplies input clock for timer KB0*/
    TKB1EN = 1U;    /* supplies input clock for timer KB1*/
    TKB2EN = 1U;    /* supplies input clock for timer KB2*/
    TPS2 = _00_TMKB_CK20_FCLK_0;
    PFSEL0 |= _08_TMKB_KB2_TRIGGER_SOURCE;
    /* Mask TMKB2 interrupt */
    TMKBMK2 = 1U;   /* disable INTTMKB2 interrupt */
    TMKBIF2 = 0U;   /* clear INTTMKB2 interrupt flag */
    /* TMKB2 used as standalone mode */
    TKBCTL21 = _00_TMKB_OPERATION_DISABLED | _00_TMKB_CK20_SELECTED | _00_TMKB_TKBCKSn_SELECTED |
               _00_TMKB_STANDALONE_MASTER;
    TKBCTL20 = _0000_TMKB_OUTPUT_GATE0_DISABLE | _0000_TMKB_OUTPUT_GATE1_DISABLE | _0000_TMKB_SMOOTH_START0_DISABLE |
               _0000_TMKB_SMOOTH_START1_DISABLE | _0000_TMKB_DITHERING0_DISABLE | _0000_TMKB_DITHERING1_DISABLE |
               _0000_TMKB_MAXFREQ_DISABLE | _0000_TMKB_BATCH_OVERWRITE_DISABLE | _0000_TMKB_TRIGGER_DISABLED;
    TKBIOC20 = _00_TMKB_OUTPUT0_ACTIVE_HIGH | _00_TMKB_OUTPUT0_DEFAULT_LOW;
    TKBCR20 = _0C7F_TMKB_CYCLE20_VALUE;
    TKBCR21 = _0C80_TMKB_DUTY21_VALUE;
    TKBCR22 = _0140_TMKB_DELAY22_VALUE;
    TKBCR23 = _0780_TMKB_DUTY23_VALUE;
    TKBTGCR2 = _0C80_TMKB_TKBTGCR2_VALUE;
    /* Set TKBO20 pin */
    POM20 &= 0xEFU;
    PM20 &= 0xEFU;
    P20 &= 0xEFU;
}

/***********************************************************************************************************************
* Function Name: R_TMR_KB2_Start
* Description  : This function starts TMKB2 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KB2_Start(void)
{
    TKBCE2 = 1U;    /* enable timer count operation */
    TKBIOC21 = _01_TMKB_PIN0_OUTPUT_ENABLED;
}

/***********************************************************************************************************************
* Function Name: R_TMR_KB2_Stop
* Description  : This function stops TMKB2 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KB2_Stop(void)
{
    TKBCE2 = 0U;    /* disable timer count operation */
    TKBIOC21 = _00_TMKB_PIN0_OUTPUT_DISABLED;
}

/***********************************************************************************************************************
* Function Name: R_TMR_KC0_Create
* Description  : This function initializes the TMKCn module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KC0_Create(void)
{
    TKC0EN = 1U;    /* supplies input clock */
    TPS2 |= _00_TMKC_CK21_FCLK_0;
    /* Mask TMKC0 interrupt */
    TMKCMK0 = 1U;   /* disable INTMKC0 interrupt */
    TMKCIF0 = 0U;   /* clear INTMKC0 interrupt flag */
    /* TMKC0 used as standalone mode */
    TKCCTL0 = _00_TMKC_OPERATION_DISABLED | _10_TMKC_CK21_SELECTED | _00_TMKC_STANDALONE_MASTER;
    TKCIOC00 = _0000_TMKC_OUTPUT2_DEFAULT_LOW | _0000_TMKC_OUTPUT2_ACTIVE_HIGH;
    TKCIOC01 = _01_TMKC_TIMER_OUTPUT0_ENABLED | _02_TMKC_TIMER_OUTPUT1_ENABLED | _04_TMKC_TIMER_OUTPUT2_ENABLED |
               _08_TMKC_TIMER_OUTPUT3_ENABLED | _10_TMKC_TIMER_OUTPUT4_ENABLED | _20_TMKC_TIMER_OUTPUT5_ENABLED;
    TKCCR0 = _013F_TMKC_CYCLE0_VALUE;
    TKCDUTY00 = _00A0_TMKC_DUTY0_VALUE;
    TKCDUTY01 = _00A0_TMKC_DUTY1_VALUE;
    TKCDUTY02 = _0050_TMKC_DUTY2_VALUE;
    TKCDUTY03 = _00A0_TMKC_DUTY3_VALUE;
    TKCDUTY04 = _00A0_TMKC_DUTY4_VALUE;
    TKCDUTY05 = _00A0_TMKC_DUTY5_VALUE;
    /* Set TKCO02 pin */
    POM20 &= 0xF7U;
    P20 &= 0xF7U;
    PM20 &= 0xF7U;
}

/***********************************************************************************************************************
* Function Name: R_TMR_KC0_Start
* Description  : This function starts TMKC channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KC0_Start(void)
{
    TOETKC0 = _00_TMKC_TIMER_TKCO00_DISABLED | _00_TMKC_TIMER_TKCO01_DISABLED | _04_TMKC_TIMER_TKCO02_ENABLED |
              _00_TMKC_TIMER_TKCO03_DISABLED | _00_TMKC_TIMER_TKCO04_DISABLED | _00_TMKC_TIMER_TKCO05_DISABLED;
    TKCCE0 = 1U;    /* enables timer count operation */
}

/***********************************************************************************************************************
* Function Name: R_TMR_KC0_Stop
* Description  : This function stops TMKC channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KC0_Stop(void)
{
    TKCCE0 = 0U;    /* stops timer operation */
    TOETKC0 = _00_TMKC_TIMER_TKCO00_DISABLED | _00_TMKC_TIMER_TKCO01_DISABLED | _00_TMKC_TIMER_TKCO02_DISABLED |
              _00_TMKC_TIMER_TKCO03_DISABLED | _00_TMKC_TIMER_TKCO04_DISABLED | _00_TMKC_TIMER_TKCO05_DISABLED;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
