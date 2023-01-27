/*
 * UART_Services.c
 *
 * Created: 10/6/2022 6:08:13 PM
 *  Author: Elwazeer
 */ 

#include "UART_Services.h"
/*#include "../../HAL/LCD/LCD_Driver.h"*/

static u8 *Asych_Send_Str  = NULLptr;
static u8 *Asych_Receive_Str  = NULLptr;

static volatile u8 flaggg = 1;

/*************************** String **********************/

void UART_SendString(u8 *str)
{
	for(u8 i=0; str[i] != '\0' ; i++)
		UART_SendBye(str[i]);
}

void UART_ReceiveString(u8 *Str)
{
	u8 i =0;
	Str[i] = UART_ReceiveByte();
	
	// When Push Enter exit from loop
	while(Str[i] != 0x0d)
	{
		i++;
		Str[i] = UART_ReceiveByte();
	}
	Str[i] = '\0';
}


/***************************** Numbers **************************/

void UART_SendNum_u16(u16 num)
{
	UART_SendBye((u8) num);
	UART_SendBye((u8) (num >> 8));
	
}

void UART_SendNum_u32(u32 num)
{
	UART_SendBye((u8) num);
	UART_SendBye((u8) (num >> 8));
	UART_SendBye((u8) (num >> 16));
	
}

u16 UART_ReceiveNum_u16(void)
{
	u16 num = UART_ReceiveByte();
	num |= UART_ReceiveByte() << 8;
	
	return num;
}

u32 UART_ReceiveNum_u32(void)
{
	u32 num = UART_ReceiveByte();
	num |= (u32) UART_ReceiveByte() << 8;
	num |= (u32) UART_ReceiveByte() << 16;
	
	return num;
}

 ////////////////////////////// Send Asynch ////////////////////////////////////

void UART_SendStringAsynch(u8 *str)
{
	UART_TX_InterruptEnable();
	UART_TX_SetCallBack(Func_TX);
	UART_SendByteNoBlock(str[0]);
	Asych_Send_Str = str;	
}

void Func_TX(void)
{
	static u8 i =1;
	if (Asych_Send_Str[i] != '\0')
	{
		UART_SendByteNoBlock(Asych_Send_Str[i]);
		i++;		
	}
	else
	{
		i = 1;
	}
}


//////////////////////////////////  Send Asynch with no interrupt ////////
void UART_SendStringAsynch_NoCodeInt(u8 *str)
{
	static u8 i = 0;
	
	UART_TX_SetCallBack(Send_Int_Function2);
	UART_TX_InterruptEnable();

	if(flaggg == 1)
	{
		if(str[i] != '\0')
		{
			
			UART_SendByteNoBlock(str[i]);
			i++;
			flaggg = 0;
		}
		else
		{
			i = 0 ;
		}
	}
}

static void Send_Int_Function2(void)
{
	flaggg=1;
}




/////////////////////////////////// Receive Asynch /////////////////////////////////

void UART_ReceiveStringAsynch(u8 *str)
{
	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(Func_RX);
	Asych_Receive_Str = str;
	
}

void Func_RX(void)
{
	static u8 i = 0;
	Asych_Receive_Str[i] = UART_ReceiveByteNoBlock();
	i++; 
}

 ////////////////////////////////////////////////////////////////
void UART_SendString_MyProtocol(u8 *str)
{
	u8 len = 0 , i=0;
	u16 sum = 0;
	
	while(str[len] != '\0')
	{
		sum += str[len];
		len++;
	}
	UART_SendBye(len);
	while(str[i] != '\0')
	{
		UART_SendBye(str[i]);
		i++;
	}
	UART_SendBye((u8) sum);
	UART_SendBye((u8) sum >> 8);
}

/*********************** create special frame *************************/ 


u8 UART_ReceiveString_MyProtocol(u8 *str)
{
	u8 i=0 , len =0;
	u16 sum_rec =0 , sum_check =0 ;
	u8 firstbyte , secondbyte ;
	
	len = UART_ReceiveByte();
	
	while(i < len)
	{
		str[i] = UART_ReceiveByte();
		sum_rec += str[i];
		i++;
	}
	/*str[i] = '\0';*/
	firstbyte = UART_ReceiveByte();
	secondbyte =  UART_ReceiveByte();
	
	sum_check = firstbyte | (secondbyte << 8);
	
	/***************** Test *****************/
	/*LCD_GOTO(0 , 5);
	LCD_WriteNumber(len);
	LCD_GOTO(0 , 8);
	LCD_WriteNumber(sum_check);
	LCD_GOTO(0 , 12);
	LCD_WriteNumber(sum_rec);*/
	
	if (sum_check == sum_rec)
		return 1;
	else
		return 0;
	
}