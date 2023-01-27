/*
 * DIO_2.h
 *
 * Created: 9/4/2022 7:16:04 PM
 *  Author: Elwazeer
 */ 


#ifndef DIO_2_H_
#define DIO_2_H_

#include "DIO_types_2.h"
#include "../../BIT_Math.h"
#include "../../ATMEGA32_REG.h"
#include "../../Std_types.h"




/************************** PORT Direction (Input or Output)********/
void DIO_2_PortDirection(DIO_2_Port_ID port_ID , DIO_2_Direction direction);

/************************* PORT Direction Value (EX: 0b00110101) ***/
void DIO_2_PortDirectionValue(DIO_2_Port_ID port_ID , u8 value); 

/************************ Pin Direction (Input or Output)********/
void DIO_2_PinDirection(DIO_2_Port_ID port_ID,DIO_2_Pin_ID pin_ID ,DIO_2_Direction direction);

 /*************************** Write value on Port  *******************/
void DIO_2_SetPortValue(DIO_2_Port_ID port_ID , u8 value);

/********************************* SET (HIGH) OR Clear (LOW) Pin value ***/ 
void DIO_2_SetPinValue(DIO_2_Port_ID port_ID,DIO_2_Pin_ID Pin_ID , DIO_2_Value value);

 /************************ Read value Form Port **************************/
u8 DIO_2_GetPortValue(DIO_2_Port_ID port);

/************************** Read Value of Pin (One or Zero) **********/ 
DIO_2_Value DIO_2_GetPinValue(DIO_2_Port_ID port_ID , DIO_2_Pin_ID pin_ID );

/*************************** Toggle Pin **************************/
void DIO_2_TogglePin(DIO_2_Port_ID port_ID ,DIO_2_Pin_ID Pin_ID );





#endif /* DIO_2_H_ */