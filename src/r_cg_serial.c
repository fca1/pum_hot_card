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
* File Name    : r_cg_serial.c
* Version      : CodeGenerator for RL78/I1A V2.04.03.01 [28 Oct 2018]
* Device(s)    : R5F107DE
* Tool-Chain   : GCCRL78
* Description  : This file implements device driver for Serial module.
* Creation Date: 11/04/2021
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t * gp_uart1_tx_address;   /* uart1 transmit buffer address */
volatile uint16_t  g_uart1_tx_cnt;        /* uart1 transmit data number */
volatile uint8_t * gp_uart1_rx_address;   /* uart1 receive buffer address */
volatile uint16_t  g_uart1_rx_cnt;        /* uart1 receive data number */
volatile uint16_t  g_uart1_rx_len;        /* uart1 receive data length */
volatile uint8_t * gp_uart4_tx_address;   /* uart4 transmit buffer address */
volatile uint16_t  g_uart4_tx_cnt;        /* uart4 transmit data number */
volatile uint8_t * gp_uart4_rx_address;   /* uart4 receive buffer address */
volatile uint16_t  g_uart4_rx_cnt;        /* uart4 receive data number */
volatile uint16_t  g_uart4_rx_len;        /* uart4 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SAU0_Create
* Description  : This function initializes the SAU0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Create(void)
{
    SAU0EN = 1U;    /* supply SAU0 clock */
    NOP();
    NOP();
    NOP();
    NOP();
    SPS0 = _0002_SAU_CK00_FCLK_2 | _0020_SAU_CK01_FCLK_2;
    R_UART1_Create();
}

/***********************************************************************************************************************
* Function Name: R_UART1_Create
* Description  : This function initializes the UART1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART1_Create(void)
{
    ST0 |= _0008_SAU_CH3_STOP_TRG_ON | _0004_SAU_CH2_STOP_TRG_ON;    /* disable UART1 receive and transmit */
    STMK1 = 1U;   /* disable INTST1 interrupt */
    STIF1 = 0U;   /* clear INTST1 interrupt flag */
    SRMK1 = 1U;   /* disable INTSR1 interrupt */
    SRIF1 = 0U;   /* clear INTSR1 interrupt flag */
    /* Set INTST1 level1 priority */
    STPR11 = 0U;
    STPR01 = 1U;
    /* Set INTSR1 low priority */
    SRPR11 = 1U;
    SRPR01 = 1U;
    SMR02 = _0020_SAU_SMRMN_INITIALVALUE | _8000_SAU_CLOCK_SELECT_CK01 | _0000_SAU_TRIGGER_SOFTWARE |
            _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR02 = _8000_SAU_TRANSMISSION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 |
            _0007_SAU_LENGTH_8;
    SDR02 = _CE00_UART1_TRANSMIT_DIVISOR;
    NFEN0 |= _04_SAU_RXD1_FILTER_ON;
    SIR03 = _0004_SAU_SIRMN_FECTMN | _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;
    SMR03 = _0020_SAU_SMRMN_INITIALVALUE | _8000_SAU_CLOCK_SELECT_CK01 | _0100_SAU_TRIGGER_RXD | _0000_SAU_EDGE_FALL |
            _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR03 = _4000_SAU_RECEPTION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 |
            _0007_SAU_LENGTH_8;
    SDR03 = _CE00_UART1_RECEIVE_DIVISOR;
    SO0 |= _0004_SAU_CH2_DATA_OUTPUT_1;
    SOL0 |= _0000_SAU_CHANNEL2_NORMAL;    /* output level normal */
    SOE0 |= _0004_SAU_CH2_OUTPUT_ENABLE; /* enable UART1 output */
    /* Set RxD1 pin */
    PMC0 &= 0xF7U;
    PM0 |= 0x08U;
    /* Set TxD1 pin */
    PMC0 &= 0xFBU;
    P0 |= 0x04U;
    PM0 &= 0xFBU;
}

/***********************************************************************************************************************
* Function Name: R_UART1_Start
* Description  : This function starts the UART1 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART1_Start(void)
{
    SO0 |= _0004_SAU_CH2_DATA_OUTPUT_1;    /* output level normal */
    SOE0 |= _0004_SAU_CH2_OUTPUT_ENABLE;    /* enable UART1 output */
    SS0 |= _0008_SAU_CH3_START_TRG_ON | _0004_SAU_CH2_START_TRG_ON;    /* enable UART1 receive and transmit */
    STIF1 = 0U;   /* clear INTST1 interrupt flag */
    SRIF1 = 0U;   /* clear INTSR1 interrupt flag */
    STMK1 = 0U;   /* enable INTST1 interrupt */
    SRMK1 = 0U;   /* enable INTSR1 interrupt */
}

/***********************************************************************************************************************
* Function Name: R_UART1_Stop
* Description  : This function stops the UART1 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART1_Stop(void)
{
    STMK1 = 1U;   /* disable INTST1 interrupt */
    SRMK1 = 1U;   /* disable INTSR1 interrupt */
    ST0 |= _0008_SAU_CH3_STOP_TRG_ON | _0004_SAU_CH2_STOP_TRG_ON;    /* disable UART1 receive and transmit */
    SOE0 &= ~_0004_SAU_CH2_OUTPUT_ENABLE;    /* disable UART1 output */
    STIF1 = 0U;   /* clear INTST1 interrupt flag */
    SRIF1 = 0U;   /* clear INTSR1 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_UART1_Receive
* Description  : This function receives UART1 data.
* Arguments    : rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UART1_Receive(uint8_t * const rx_buf, uint16_t rx_num)
{
    MD_STATUS status = MD_OK;

    if (rx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_uart1_rx_cnt = 0U;
        g_uart1_rx_len = rx_num;
        gp_uart1_rx_address = rx_buf;
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_UART1_Send
* Description  : This function sends UART1 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UART1_Send(uint8_t * const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        gp_uart1_tx_address = tx_buf;
        g_uart1_tx_cnt = tx_num;
        STMK1 = 1U;    /* disable INTST1 interrupt */
        TXD1 = *gp_uart1_tx_address;
        gp_uart1_tx_address++;
        g_uart1_tx_cnt--;
        STMK1 = 0U;    /* enable INTST1 interrupt */
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_SAU4_Create
* Description  : This function initializes the SAU4 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU4_Create(void)
{
    DALIEN = 1U;    /* supply SAU4 clock */
    NOP();
    NOP();
    NOP();
    NOP();
    SPS4 = _0005_SAU_CK40_FCLK_2;
    R_UART4_Create();
}

/***********************************************************************************************************************
* Function Name: R_UART4_Create
* Description  : This function initializes the UART4 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART4_Create(void)
{
    ST4 |= _0002_SAU_CH1_STOP_TRG_ON | _0001_SAU_CH0_STOP_TRG_ON;    /* disable UART4 receive and transmit */
    STDLMK4 = 1U;   /* disable INTSTDL4 interrupt */
    STDLIF4 = 0U;   /* clear INTSTDL4 interrupt flag */
    SRDLMK4 = 1U;   /* disable INTSRDL4 interrupt */
    SRDLIF4 = 0U;   /* clear INTSRDL4 interrupt flag */
    /* Set INTSTDL4 level1 priority */
    STDLPR14 = 0U;
    STDLPR04 = 1U;
    /* Set INTSR4 low priority */
    SRDLPR14 = 1U;
    SRDLPR04 = 1U;
    SMR40 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_TRIGGER_SOFTWARE |
            _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR40 = _8000_SAU_TRANSMISSION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 |
            _0007_SAU_LENGTH_8;
    SDR40 = _CE00_UART4_TRANSMIT_DIVISOR;
    SIR41 = _0080_SAU_SIRMN_MFECTMN | _0004_SAU_SIRMN_FECTMN | _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;
    SMR41 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0100_SAU_TRIGGER_RXD | _0000_SAU_EDGE_FALL |
            _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR41 = _4000_SAU_RECEPTION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 |
            _0007_SAU_LENGTH_8;
    SDR41 = _CE00_UART4_RECEIVE_DIVISOR;
    SO4 |= _0001_SAU_CH0_DATA_OUTPUT_1;
    SOL4 |= _0000_SAU_CHANNEL0_NORMAL;    /* output level normal */
    SOE4 |= _0001_SAU_CH0_OUTPUT_ENABLE; /* enable UART4 output */
    /* Set DALIRxD4 pin */
    PM20 |= 0x40U;
    /* Set DALITxD4 pin */
    P20 |= 0x20U;
    PM20 &= 0xDFU;
}

/***********************************************************************************************************************
* Function Name: R_UART4_Start
* Description  : This function starts the UART4 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART4_Start(void)
{
    SO4 |= _0001_SAU_CH0_DATA_OUTPUT_1;    /* output level normal */
    SOE4 |= _0001_SAU_CH0_OUTPUT_ENABLE;    /* enable UART4 output */
    SS4 |= _0002_SAU_CH1_START_TRG_ON | _0001_SAU_CH0_START_TRG_ON;    /* enable UART4 receive and transmit */
    STDLIF4 = 0U;   /* clear INTSTDL4 interrupt flag */
    SRDLIF4 = 0U;   /* clear INTSRDL4 interrupt flag */
    STDLMK4 = 0U;   /* enable INTSTDL4 interrupt */
    SRDLMK4 = 0U;   /* enable INTSRDL4 interrupt */
}

/***********************************************************************************************************************
* Function Name: R_UART4_Stop
* Description  : This function stops the UART4 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART4_Stop(void)
{
    STDLMK4 = 1U;   /* disable INTSTDL4 interrupt */
    SRDLMK4 = 1U;   /* disable INTSRDL4 interrupt */
    ST4 |= _0002_SAU_CH1_STOP_TRG_ON | _0001_SAU_CH0_STOP_TRG_ON;    /* disable UART4 receive and transmit */
    SOE4 &= ~_0001_SAU_CH0_OUTPUT_ENABLE;    /* disable UART4 output */
    STDLIF4 = 0U;   /* clear INTSTDL4 interrupt flag */
    SRDLIF4 = 0U;   /* clear INTSRDL4 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_UART4_Receive
* Description  : This function receives UART4 data.
* Arguments    : rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UART4_Receive(uint8_t * const rx_buf, uint16_t rx_num)
{
    MD_STATUS status = MD_OK;

    if (rx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_uart4_rx_cnt = 0U;
        g_uart4_rx_len = rx_num;
        gp_uart4_rx_address = rx_buf;
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_UART4_Send
* Description  : This function sends UART4 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UART4_Send(uint8_t * const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        gp_uart4_tx_address = tx_buf;
        g_uart4_tx_cnt = tx_num;
        STDLMK4 = 1U;    /* disable INTSTDL4 interrupt */
        TXD4 = *gp_uart4_tx_address;
        gp_uart4_tx_address++;
        g_uart4_tx_cnt--;
        STDLMK4 = 0U;    /* enable INTSTDL4 interrupt */
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
