/*
 * UART.c
 *
 * Created: 10/5/2022 10:26:48 PM
 *  Author: Elwazeer
 */ 


#include "UART_driver.h"
#include "UART_config.h"

/********************* pointer TO fuunction *****************/

static void(*TX_Fptr)(void) =  NULLptr;
static void(*RX_Fptr)(void) =  NULLptr;


/********************************************initialization ****************/


void UART_Iint(void)
{
	u16 UBRR_var=0; 
	u8  UCSRC_var=0;
	
	
	//******************set URSEL to write data to UCSRC register**************/ 
	SET_BIT(UCSRC_var , URSEL);
	
	/********************speed mode*************************/
	#if (SPEED_MODE == NORMAL_SPEED)
	CLEAR_BIT(UCSRA , U2X);
	#elif (SPEED_MODE == DOUBLE_SPEED)
	SET_BIT(UCSRA , U2X);
	#endif
	
	/*******************parity mode*************************/
	#if (PARITY_MODE == NO_PARITY)
	CLEAR_BIT(UCSRC_var , UPM0);
	CLEAR_BIT(UCSRC_var , UPM1);
	#elif (PARITY_MODE == EVEN_PARITY)
	CLEAR_BIT(UCSRC_var , UPM0);
	SET_BIT(UCSRC_var , UPM1);
	#elif (PARITY_MODE == ODD_PARITY)
	SET_BIT(UCSRC_var , UPM0);
	SET_BIT(UCSRC_var , UPM1);
	#endif
	
	/***************      sync mode*************************/
	
	#if (SYNCH_MODE == SYNCH)
	CLEAR_BIT(UCSRC_var , UMSEL);
	#elif (SYNCH_MODE == ASYNCH)
	SET_BIT(UCSRC_var , UMSEL);
	#endif
	
	/************    number of stop bits*****************/
	
	#if (N_STOP_BITS == ONE_STOP_BIT)
	CLEAR_BIT(UCSRC_var , USBS);
	#elif (N_STOP_BITS == TWO_STOP_BIT)
	SET_BIT(UCSRC_var , USBS);
	#endif
	
	/*************** number of data bits********************/
	
	#if (N_DATA_BITS == _5_DATA_BITS)
	CLEAR_BIT(UCSRC_var , UCSZ0);
	CLEAR_BIT(UCSRC_var , UCSZ1);
	CLEAR_BIT(UCSRB , UCSZ2);
	#elif (N_DATA_BITS == _6_DATA_BITS)
	SET_BIT(UCSRC_var , UCSZ0);
	CLEAR_BIT(UCSRC_var , UCSZ1);
	CLEAR_BIT(UCSRB , UCSZ2);
	#elif (N_DATA_BITS == _7_DATA_BITS)
	CLEAR_BIT(UCSRC_var , UCSZ0);
	SET_BIT(UCSRC_var , UCSZ1);
	CLEAR_BIT(UCSRB , UCSZ2);
	#elif (N_DATA_BITS == _8_DATA_BITS) 
	SET_BIT(UCSRC_var , UCSZ0);
	SET_BIT(UCSRC_var , UCSZ1);
	CLEAR_BIT(UCSRB , UCSZ2);
	#elif (N_DATA_BITS == _9_DATA_BITS)
	SET_BIT(UCSRC_var , UCSZ0);
	SET_BIT(UCSRC_var , UCSZ1);
	SET_BIT(UCSRB , UCSZ2);
	#endif
	
	//*****************set UCSRC value   *******************************/
	UCSRC=UCSRC_var;

	//************************Baud rate *******************************/
	
	#if (SPEED_MODE == NORMAL_SPEED)
	UBRR_var =  F_CPU / ((u32)16 * BUAD_RATE) - 1;
	#elif (SPEED_MODE == DOUBLE_SPEED)
	UBRR_var =  F_CPU / ((u32)8 * BUAD_RATE) - 1;
	#endif
	
	UBRRH = (u8) (UBRR_var >> 8);
	UBRRL = (u8) UBRR_var ;
	
	//************************Enable  *******************************/
	//enable UART  receiver.
	SET_BIT(UCSRB,RXEN);
	//enable UART  transmitter .
	SET_BIT(UCSRB,TXEN);
	
}


/************************ Send & receive with polling*****************/

void UART_SendBye(u8 data)
{
	while(!GET_BIT(UCSRA , UDRE));
	UDR = data;
}

u8 UART_ReceiveByte(void)
{
	while(!GET_BIT(UCSRA , RXC));
	return UDR;
}


u8 UART_ReceiveNoBlock(u8 *pdata)
{
	if(GET_BIT(UCSRA , UDRE))
	{
		*pdata = UDR;
		return 1;
	}
	else
	return 0;
}

/****************************** Send & receive function with no checking*****/
void UART_SendByteNoBlock(u8 data)
{
	UDR = data;
}

u8 UART_ReceiveByteNoBlock(void)
{
	return UDR;
}



/********************************* interrupt *******************************/

void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB , RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB , RXCIE);
}


void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB , TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB , TXCIE);
}

/************************************* Set CallBack **************/

void UART_TX_SetCallBack(void(*localptr)(void))
{
	TX_Fptr = localptr;
}


void UART_RX_SetCallBack(void(*localptr)(void))
{
	RX_Fptr = localptr;
}
/****************************** ISR *****************************/
ISR(USART_TXC_vect)
{
	if (TX_Fptr != NULLptr)
		TX_Fptr();
}

ISR(USART_RXC_vect)
{
	if (RX_Fptr != NULLptr)
	RX_Fptr();
}