/*
 * UART_Stack.h
 *
 * Created: 10/10/2022 5:07:39 PM
 *  Author: Elwazeer
 */ 


#ifndef UART_STACK_H_
#define UART_STACK_H_

#include "../../Std_types.h"

#define STACKSIZE 10

typedef enum{
	Stack_Empty,
	Stack_Full,
	Stack_Done
	}Stack_Status;

Stack_Status Push(u8 data);
Stack_Status Pop(u8 *pdata);




#endif /* UART_STACK_H_ */