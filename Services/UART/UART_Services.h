/*
 * UART_Services.h
 *
 * Created: 10/6/2022 6:08:30 PM
 *  Author: Elwazeer
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "../../MCAL/UART/UART_driver.h" 

/************************** String *********************/

void UART_SendString(u8 *str);
void UART_ReceiveString(u8 *Str);

/********************* Numbers ***************************/

void UART_SendNum_u16(u16 num);
void UART_SendNum_u32(u32 num);
u16 UART_ReceiveNum_u16(void);
u32 UART_ReceiveNum_u32(void);

/******************************** Asynch ******************/

void UART_SendStringAsynch(u8 *str);
void Func_TX(void);

void UART_ReceiveStringAsynch(u8 *str);
void Func_RX(void);

void UART_SendStringAsynch_NoCodeInt(u8 *str);
static void Send_Int_Function2(void);


void UART_SendString_MyProtocol(u8 *str);
u8 UART_ReceiveString_MyProtocol(u8 *str);

#endif /* UART_SERVICES_H_ */