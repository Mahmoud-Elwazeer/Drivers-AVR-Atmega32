/*
 * SPI_driver.c
 *
 * Created: 10/19/2022 5:21:46 PM
 *  Author: Elwazeer
 */ 


#include "SPI_driver.h"

void SPI_InitMaster(void)
{
	
	
	// master
	SET_BIT(SPCR , MSTR);
	
	// clock rate
	
	/********************speed mode*************************/
	#if (SPEED_MODE == NORMAL_SPEED)
	CLEAR_BIT(SPSR , SPI2X);
	#elif (SPEED_MODE == DOUBLE_SPEED)
	SET_BIT(SPSR , SPI2X);
	#endif
	
	/******************** SCK Fequency ************************/
	#if (SCK_F == SCK_F_div_4)
	CLEAR_BIT(SPCR , SPR0);
	CLEAR_BIT(SPCR , SPR1);
	#elif (SCK_F == SCK_F_div_16)
	SET_BIT(SPCR , SPR0);
	CLEAR_BIT(SPCR , SPR1);
	#elif (SCK_F == SCK_F_div_64)
	CLEAR_BIT(SPCR , SPR0);
	SET_BIT(SPCR , SPR1);
	#elif (SCK_F == SCK_F_div_128)
	SET_BIT(SPCR , SPR0);
	SET_BIT(SPCR , SPR1);
	#endif
	
	
	
	// Enable SPI
	SET_BIT(SPCR , SPE);
}

void SPI_InitSlave(void)
{
	//  slave
	CLEAR_BIT(SPCR , MSTR);
	
	// Enable SPI
	SET_BIT(SPCR , SPE);
}

void SPI_SentByte(u8 data)
{
	SPDR = data;//move the given data to SPI Data register
	
	while(!GET_BIT(SPSR , SPIF));
	
}

u8 SPI_ReceiveByte()
{
	while(!GET_BIT(SPSR , SPIF));
	return SPDR;
}


/****************************** Send & receive function with no checking*****/
void SPI_SendByteNoBlock(u8 data)
{
	SPDR = data;
}

u8 SPI_ReceiveByteNoBlock(void)
{
	return SPDR;
}