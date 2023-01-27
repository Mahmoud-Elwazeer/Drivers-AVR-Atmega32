/*
 * I2C_driver.c
 *
 * Created: 12/8/2022 2:24:17 PM
 *  Author: Elwazeer
 */ 

#include "I2C_driver.h"

void I2C_Init()
{
	
	/*To calculate SCL use Equation:
	* SCL = F_CPU /(16 + (2*TWBR*(4^TWPS)))
	*/
	
	TWBR = I2C_TWBR_VALUE;
	
	TWSR = 0x00;
	TWSR &= (0xF8 | I2C_TWPS_VALUE);      //11111 000
	
}

void I2C_StartCondition(void)
{
	// Clear TWI interrupt flag, Put start condition , Enable TWI
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT))); // Wait till start condition is transmitted
	while((TWSR & 0xF8)!= I2C_START_SENT); // Check for the acknowledgement
}


void I2C_StopCondition(void)
{
	// Clear TWI interrupt flag, Put stop condition , Enable TWI
	TWCR= (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void I2C_WriteData(u8 data)
{
	TWDR=data;    // put data in TWDR
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	
	 // Check for the acknoledgement
	//while((TWSR & 0xF8) != I2C_DATA_SENT_WITH_ACK);
}

u8 I2C_ReadDataAck(void)
{
	// Clear TWI interrupt flag,Enable TWI , Enable Ack
	TWCR = TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	
	return TWDR;
}

u8 I2C_ReadDataNAck(void)
{
	// Clear TWI interrupt flag,Enable TWI 
	TWCR = TWCR=(1<<TWINT)|(1<<TWEN);
	
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	
	return TWDR;
}


u8 I2C_CheckStatus(void)
{
	u8 status;
	status = TWSR & 0xF8;
	
	return status;
}

