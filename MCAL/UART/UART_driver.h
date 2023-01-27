/*
 * UART.h
 *
 * Created: 10/5/2022 10:27:01 PM
 *  Author: Elwazeer
 */ 


#ifndef UART_H_
#define UART_H_

#include "../DIO/DIO.h"

void UART_Iint(void);


void UART_SendBye(u8 data);
void UART_SendByteNoBlock(u8 data);


u8 UART_ReceiveByte(void);
u8 UART_ReceiveNoBlock(u8 *pdata);
u8 UART_ReceiveByteNoBlock(void);


void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_RX_SetCallBack(void(*localptr)(void));


void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
void UART_TX_SetCallBack(void(*localptr)(void));


#endif /* UART_H_ */