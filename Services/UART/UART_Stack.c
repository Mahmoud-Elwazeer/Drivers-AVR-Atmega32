/*
 * UART_Stack.c
 *
 * Created: 10/10/2022 5:07:17 PM
 *  Author: Elwazeer
 */ 

#include "UART_Stack.h"

static u8 Stack[STACKSIZE];
static u8 SP = 0;

Stack_Status Push(u8 data)
{
	Stack_Status status;
	
	if(SP ==  STACKSIZE)
	{
		status=  Stack_Full;
	}
	else
	{
		Stack[SP] = data;
		SP++;
		status = Stack_Done;
	}
	
	return status;
}

Stack_Status Pop(u8 *pdata)
{
	Stack_Status status;
	
	if(SP ==  0)
	{
		status=  Stack_Empty;
	}
	else
	{
		SP--;
		*pdata = Stack[SP];
		status = Stack_Done;
	}
	
	return status;
}