/*
 * SPI_driver.h
 *
 * Created: 10/19/2022 5:22:01 PM
 *  Author: Elwazeer
 */ 


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include "../DIO/DIO.h"
#include "SPI_Config.h"


/*
             SET BIT MOSI , SCK as Output in DIO_Config 
             if we use as master always  SET SS as Output 
			 if we use SS as Input when getting 1 ==> work as a master
			                            getting 0 ==> work as slave
			 
 */
void SPI_InitMaster(void);

/*            SET BIT MISO as Output in DIO_Config                   */
void SPI_InitSlave(void);

void SPI_SentByte(u8 data);

u8 SPI_ReceiveByte();

void SPI_SendByteNoBlock(u8 data);

u8 SPI_ReceiveByteNoBlock(void);

#endif /* SPI_DRIVER_H_ */