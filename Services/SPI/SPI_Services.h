/*
 * SPI_Services.h
 *
 * Created: 11/27/2022 5:04:32 PM
 *  Author: Elwazeer
 */ 


#ifndef SPI_SERVICES_H_
#define SPI_SERVICES_H_

#include "../../MCAL/SPI/SPI_driver.h"

/********************** String **********************/

void SPI_SendString(u8 *str);
void SPI_ReceiveString(u8 *Str);

/******************** Numbers *********************/
void SPI_SendNum_u16(u16 num);
void SPI_SendNum_u32(u32 num);

u16 SPI_ReceiveNum_u16(void);
u32 SPI_ReceiveNum_u32(void);

#endif /* SPI_SERVICES_H_ */