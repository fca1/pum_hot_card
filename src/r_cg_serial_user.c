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
* File Name    : r_cg_serial_user.c
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
extern volatile uint8_t * gp_uart1_tx_address;        /* uart1 transmit buffer address */
extern volatile uint16_t  g_uart1_tx_cnt;             /* uart1 transmit data number */
extern volatile uint8_t * gp_uart1_rx_address;        /* uart1 receive buffer address */
extern volatile uint16_t  g_uart1_rx_cnt;             /* uart1 receive data number */
extern volatile uint16_t  g_uart1_rx_len;             /* uart1 receive data length */
extern volatile uint8_t * gp_uart4_tx_address;        /* uart4 transmit buffer address */
extern volatile uint16_t  g_uart4_tx_cnt;             /* uart4 transmit data number */
extern volatile uint8_t * gp_uart4_rx_address;        /* uart4 receive buffer address */
extern volatile uint16_t  g_uart4_rx_cnt;             /* uart4 receive data number */
extern volatile uint16_t  g_uart4_rx_len;             /* uart4 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_uart1_interrupt_receive
* Description  : This function is INTSR1 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_uart1_interrupt_receive(void)
{
    volatile uint8_t rx_data;
    volatile uint8_t err_type;

    err_type = (uint8_t)(SSR03 & 0x0007U);
    SIR03 = (uint16_t)err_type;
    rx_data = RXD1;

    if (g_uart1_rx_len > g_uart1_rx_cnt)
    {
        *gp_uart1_rx_address = rx_data;
        gp_uart1_rx_address++;
        g_uart1_rx_cnt++;

        if (g_uart1_rx_len == g_uart1_rx_cnt)
        {
            r_uart1_callback_receiveend();
        }
    }
}

/***********************************************************************************************************************
* Function Name: r_uart1_interrupt_send
* Description  : This function is INTST1 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_uart1_interrupt_send(void)
{
    if (g_uart1_tx_cnt > 0U)
    {
        TXD1 = *gp_uart1_tx_address;
        gp_uart1_tx_address++;
        g_uart1_tx_cnt--;
    }
    else
    {
        r_uart1_callback_sendend();
    }
}

/***********************************************************************************************************************
* Function Name: r_uart1_callback_receiveend
* Description  : This function is a callback function when UART1 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uart1_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_uart1_callback_sendend
* Description  : This function is a callback function when UART1 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uart1_callback_sendend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_uart4_interrupt_receive
* Description  : This function is INTSRDL4 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_uart4_interrupt_receive(void)
{
    volatile uint8_t rx_data;
    volatile uint8_t err_type;

    err_type = (uint8_t)(SSR41 & 0x0007U);
    SIR41 = (uint16_t)err_type;
    rx_data = RXD4;

    if (g_uart4_rx_len > g_uart4_rx_cnt)
    {
        *gp_uart4_rx_address = rx_data;
        gp_uart4_rx_address++;
        g_uart4_rx_cnt++;

        if (g_uart4_rx_len == g_uart4_rx_cnt)
        {
            r_uart4_callback_receiveend();
        }
    }
}

/***********************************************************************************************************************
* Function Name: r_uart4_interrupt_send
* Description  : This function is INTSTDL4 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_uart4_interrupt_send(void)
{
    if (g_uart4_tx_cnt > 0U)
    {
        TXD4 = *gp_uart4_tx_address;
        gp_uart4_tx_address++;
        g_uart4_tx_cnt--;
    }
    else
    {
        r_uart4_callback_sendend();
    }
}

/***********************************************************************************************************************
* Function Name: r_uart4_callback_receiveend
* Description  : This function is a callback function when UART4 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uart4_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_uart4_callback_sendend
* Description  : This function is a callback function when UART4 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uart4_callback_sendend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
