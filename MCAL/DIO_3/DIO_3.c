/*
 * GPIO_AVR.c
 *
 * Created: 7/30/2022 7:54:58 PM
 *  Author: Elwazeer
 */ 



#include "DIO_3.h"


void DIO_3_PortDirection(vu8* port_ID , DIO_3_Direction direction)
{
	if (direction == OUTPUT)
	*(port_ID+1) = 0xff;
	else if (direction == INPUT)
	*(port_ID+1) = 0x00;
	else if (direction == INPUT_PULL_UP)
	*(port_ID+1) = 0x00;
	*(port_ID + 2 )= 0xFF;
}


void DIO_3_PortDirectionValue(vu8* port_ID , u8 value)
{
	*(port_ID+1) = value;
	
}

void DIO_3_PinDirection(vu8* port_ID, DIO_3_Pin_ID pin_ID ,DIO_3_Direction direction)
{
	if (direction == OUTPUT)
	SET_BIT(*(port_ID+1), pin_ID);
	else if (direction == INPUT)
	CLEAR_BIT(*(port_ID+1) , pin_ID);
	else if (direction == INPUT_PULL_UP)
	{
		CLEAR_BIT(*(port_ID+1) , pin_ID);
		SET_BIT(*(port_ID+2 ), pin_ID);
	}
}

void DIO_3_SetPortValue(vu8* port_ID , u8 value)
{
	*(port_ID + 2 )= value;
}

void DIO_3_SetPinValue(vu8* port_ID,DIO_3_Pin_ID Pin_ID , DIO_3_Value value)
{
	if (value == HIGH)
	SET_BIT(*(port_ID+2 ), Pin_ID);
	else
	CLEAR_BIT(*(port_ID+2 ), Pin_ID);
}

u8 DIO_3_GetPortValue(vu8* port_ID)
{
	return *(port_ID);
	
}

DIO_3_Value DIO_3_GetPinValue(vu8* port_ID , DIO_3_Pin_ID pin_ID )
{
	return GET_BIT(*(port_ID) , pin_ID);
}

void DIO_3_TogglePin(vu8* port_ID ,DIO_3_Pin_ID Pin_ID )
{
	TOGGLE_BIT(*(port_ID), Pin_ID);
}