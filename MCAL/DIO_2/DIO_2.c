/*
 * DIO.c
 *
 * Created: 9/4/2022 7:15:54 PM
 *  Author: Elwazeer
 */ 


#include "DIO_2.h"

void DIO_2_PortDirection(DIO_2_Port_ID port_ID , DIO_2_Direction direction)
{
	if (direction == OUTPUT)
	{
		switch(port_ID)
		{
			case PA: DDRA = 0xFF ; break;
			case PB: DDRB = 0xFF ; break;
			case PC: DDRC = 0xFF ; break;
			case PD: DDRD = 0xFF ; break;
		}
	}
	else if(direction == INPUT)
	{
		switch(port_ID)
		{
			case PA: DDRA = 0x00 ; break;
			case PB: DDRB = 0x00 ; break;
			case PC: DDRC = 0x00 ; break;
			case PD: DDRD = 0x00 ; break;
		}
	}
	else if(direction == INPUT_PULL_UP)
	{
		switch(port_ID)
		{
			case PA: 
			DDRA = 0x00 ;
			PORTA = 0xFF;
			break;
			case PB:
			DDRB = 0x00 ;
			PORTB = 0xFF;
			break;
			case PC:
			DDRC = 0x00 ;
			PORTC = 0xFF;
			break;
			case PD:
			DDRD = 0x00 ;
			PORTD = 0xFF;
			break;
		}
	}
}

void DIO_2_PortDirectionValue(DIO_2_Port_ID port_ID , u8 value)
{
	switch(port_ID)
	{
		case PA: DDRA = value ; break;
		case PB: DDRB = value ; break;
		case PC: DDRC = value ; break;
		case PD: DDRD = value ; break;
	}
}


void DIO_2_PinDirection(DIO_2_Port_ID port_ID,DIO_2_Pin_ID pin_ID ,DIO_2_Direction direction)
{
	if (port_ID <= PD && pin_ID <= pin7)
	{
		
		
		if (direction == OUTPUT)
		{
			switch(port_ID)
			{
				case PA: SET_BIT(DDRA , pin_ID) ; break;
				case PB: SET_BIT(DDRB , pin_ID) ; break;
				case PC: SET_BIT(DDRC , pin_ID) ; break;
				case PD: SET_BIT(DDRD , pin_ID) ; break;
			}
		}
		else if(direction == INPUT)
		{
			switch(port_ID)
			{
				case PA: CLEAR_BIT(DDRA , pin_ID) ; break;
				case PB: CLEAR_BIT(DDRB , pin_ID) ; break;
				case PC: CLEAR_BIT(DDRC , pin_ID) ; break;
				case PD: CLEAR_BIT(DDRD , pin_ID) ; break;
			}
		}
		else if (direction == INPUT_PULL_UP)
		{
			switch(port_ID)
			{
				case PA:
				CLEAR_BIT(DDRA , pin_ID);
				SET_BIT(PORTA , pin_ID);
				break;
				case PB:
				CLEAR_BIT(DDRB , pin_ID);
				SET_BIT(PORTB , pin_ID);
				break;
				case PC:
				CLEAR_BIT(DDRC , pin_ID);
				SET_BIT(PORTC , pin_ID);
				break;
				case PD:
				CLEAR_BIT(DDRD , pin_ID);
				SET_BIT(PORTD , pin_ID);
				break;
			}
		}
	}
}


void DIO_2_SetPortValue(DIO_2_Port_ID port_ID , u8 value)
{
	switch(port_ID)
	{
		case PA: PORTA = value ; break;
		case PB: PORTB = value ; break;
		case PC: PORTC = value ; break;
		case PD: PORTD = value ; break;
	}
}

void DIO_2_SetPinValue(DIO_2_Port_ID port_ID,DIO_2_Pin_ID Pin_ID , DIO_2_Value value)
{
	if (port_ID <= PD && Pin_ID <= pin7)
	{
		
		
		if (value == HIGH)
		{
			switch(port_ID)
			{
				case PA: SET_BIT(PORTA , Pin_ID) ; break;
				case PB: SET_BIT(PORTA , Pin_ID) ; break;
				case PC: SET_BIT(PORTA , Pin_ID) ; break;
				case PD: SET_BIT(PORTA , Pin_ID) ; break;
			}
		}
		else if(value == LOW)
		{
			switch(port_ID)
			{
				case PA: CLEAR_BIT(PORTA , Pin_ID) ; break;
				case PB: CLEAR_BIT(PORTB , Pin_ID) ; break;
				case PC: CLEAR_BIT(PORTC , Pin_ID) ; break;
				case PD: CLEAR_BIT(PORTD , Pin_ID) ; break;
			}
		}
	}
}

u8 DIO_2_GetPortValue(DIO_2_Port_ID port)
{
	switch(port)
	{
		case PA: return PINA ; break;
		case PB: return PINB ; break;
		case PC: return PINC ; break;
		case PD: return PIND ; break;
		default: return 0x00 ; break;
		
	}
}

DIO_2_Value DIO_2_GetPinValue(DIO_2_Port_ID port_ID , DIO_2_Pin_ID pin_ID )
{
	if (port_ID <= PD && pin_ID <= pin7)
	{
		switch(port_ID)
		{
			case PA: return GET_BIT(PINA , pin_ID); break;
			case PB: return GET_BIT(PINB , pin_ID); break;
			case PC: return GET_BIT(PINC , pin_ID); break;
			case PD: return GET_BIT(PIND , pin_ID); break;
			default: return 0x00; break;
		}
	}
	return 0x00;
}

void DIO_2_TogglePin(DIO_2_Port_ID port_ID , DIO_2_Pin_ID Pin_ID )
{
	if (port_ID <= PD && Pin_ID <= pin7)
		{
			switch(port_ID)
			{
				case PA: TOGGLE_BIT(PORTA , Pin_ID) ; break;
				case PB: TOGGLE_BIT(PORTB , Pin_ID) ; break;
				case PC: TOGGLE_BIT(PORTC , Pin_ID) ; break;
				case PD: TOGGLE_BIT(PORTD , Pin_ID) ; break;
			}
		}
}