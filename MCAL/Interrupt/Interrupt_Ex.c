/*
 * EX_Interrupt.c
 *
 * Created: 9/10/2022 11:36:24 PM
 *  Author: Elwazeer
 */ 

#include "Interrupt_Ex.h"



static void (*INT0_fptr) (void) = NULLptr;
static void (*INT1_fptr) (void) = NULLptr;
static void (*INT2_fptr) (void) = NULLptr;

void Interrupt_Enable(Interrupt_PIN_ID interrupt)
{
	switch(interrupt)
	{
		case INT0_pin:
		SET_BIT(GICR , INT0);
		break;
		case INT1_pin:
		SET_BIT(GICR , INT1);
		break;
		case INT2_pin:
		SET_BIT(GICR , INT2);
		break;
	}
}

void Interrupt_Disable(Interrupt_PIN_ID interrupt)
{
	switch(interrupt)
	{
		case INT0_pin:
		CLEAR_BIT(GICR , INT0);
		break;
		case INT1_pin:
		CLEAR_BIT(GICR , INT1);
		break;
		case INT2_pin:
		CLEAR_BIT(GICR , INT2);
		break;
	}
}


void Interrupt_TriggerEdge(Interrupt_PIN_ID interrupt  , Interrupt_Trigger_ID Edge)
{
	switch(interrupt)
	{
		case INT0_pin:
		switch(Edge)
		{
			case LOW_LEVEL:
			CLEAR_BIT(MCUCR , ISC00);
			CLEAR_BIT(MCUCR , ISC01);
			break;
			case ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR , ISC00);
			CLEAR_BIT(MCUCR , ISC01);
			break;
			case FALLING_EDGE:
			CLEAR_BIT(MCUCR , ISC00);
			SET_BIT(MCUCR , ISC01);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR , ISC00);
			SET_BIT(MCUCR , ISC01);
			break;
		}
		break;
		case INT1_pin:
		switch(Edge)
		{
			case LOW_LEVEL:
			CLEAR_BIT(MCUCR , ISC10);
			CLEAR_BIT(MCUCR , ISC11);
			break;
			case ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR , ISC10);
			CLEAR_BIT(MCUCR , ISC11);
			break;
			case FALLING_EDGE:
			CLEAR_BIT(MCUCR , ISC10);
			SET_BIT(MCUCR , ISC11);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR , ISC10);
			SET_BIT(MCUCR , ISC11);
			break;
		}
		break;
		case INT2_pin:
		switch(Edge)
		{
			case FALLING_EDGE:
			CLEAR_BIT(MCUCSR , ISC2);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR , ISC2);
			break;
			default:
			CLEAR_BIT(MCUCSR , ISC2);
		}
		break;
	}
}

void Interrupt_CallBack(Interrupt_PIN_ID interrupt , void(*localptr)(void))
{

	switch(interrupt)
	{
		case INT0_pin:
		INT0_fptr = localptr;
		break;
		case INT1_pin:
		INT1_fptr = localptr;
		break;
		case INT2_pin:
		INT2_fptr = localptr;
		break;
	}
	
}

ISR(INT0_vect)
{
	if (INT0_fptr != NULLptr)
	{
		INT0_fptr();
	}
}

ISR(INT1_vect)
{
	if (INT1_fptr != NULLptr)
	{
		INT1_fptr();
	}
}

ISR(INT2_vect)
{
	if (INT2_fptr != NULLptr)
	{
		INT2_fptr();
	}
}