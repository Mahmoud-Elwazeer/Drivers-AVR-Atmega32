/*
 * GPIO_AVR.h
 *
 * Created: 7/30/2022 7:56:24 PM
 *  Author: Elwazeer
 */ 


#ifndef GPIO_AVR_H_
#define GPIO_AVR_H_

#include "../../ATMEGA32_REG.h"
#include "../../BIT_Math.h"
#include "DIO_Types_3.h"


/************************** PORT Direction (Input or Output)********/
void DIO_3_PortDirection(vu8* port_ID , DIO_3_Direction direction);

/************************* PORT Direction Value (EX: 0b00110101) ***/
void DIO_3_PortDirectionValue(vu8* port_ID , u8 value);

/************************ Pin Direction (Input or Output)********/
void DIO_3_PinDirection(vu8* port_ID, DIO_3_Pin_ID pin_ID ,DIO_3_Direction direction);

/*************************** Write value on Port  *******************/
void DIO_3_SetPortValue(vu8* port_ID , u8 value);

/********************************* SET (HIGH) OR Clear (LOW) Pin value ***/
void DIO_3_SetPinValue(vu8* port_ID,DIO_3_Pin_ID Pin_ID , DIO_3_Value value);

/************************ Read value Form Port **************************/
u8 DIO_3_GetPortValue(vu8* port_ID);

/************************** Read Value of Pin (One or Zero) **********/
DIO_3_Value DIO_3_GetPinValue(vu8* port_ID , DIO_3_Pin_ID pin_ID );

/*************************** Toggle Pin **************************/
void DIO_3_TogglePin(vu8* port_ID ,DIO_3_Pin_ID Pin_ID );


#endif /* GPIO_AVR_H_ */