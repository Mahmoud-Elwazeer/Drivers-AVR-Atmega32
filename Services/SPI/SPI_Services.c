/*
 * SPI_Services.c
 *
 * Created: 11/27/2022 5:04:17 PM
 *  Author: Elwazeer
 */ 


#include "SPI_Services.h"

void SPI_SendString(u8 *str)
{
	for(u8 i =0; str[i] != '\0' ; i++)
		SPI_SentByte(str[i]);
}

void SPI_ReceiveString(u8 *Str)
{
	u8 i =0;
	Str[i] = SPI_ReceiveByte();
	
	// When Push Enter exit from loop 0x0d
	while(Str[i] != '#')
	{
		i++;
		Str[i] = SPI_ReceiveByte();
	}
	Str[i] = '\0';
}

void SPI_SendNum_u16(u16 num)
{
	SPI_SentByte((u8) num);
	SPI_SentByte((u8) (num >> 8));
	
}

void SPI_SendNum_u32(u32 num)
{
	SPI_SentByte((u8) num);
	SPI_SentByte((u8) (num >> 8));
	SPI_SentByte((u8) (num >> 16));
	
}

u16 SPI_ReceiveNum_u16(void)
{
	u16 num = SPI_ReceiveByte();
	num |= SPI_ReceiveByte() << 8;
	
	return num;
}

u32 SPI_ReceiveNum_u32(void)
{
	u32 num = SPI_ReceiveByte();
	num |= (u32) SPI_ReceiveByte() << 8;
	num |= (u32) SPI_ReceiveByte() << 16;
	
	return num;
}