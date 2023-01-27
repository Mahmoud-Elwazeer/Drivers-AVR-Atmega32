/*
 * Ex_Interrupt.h
 *
 * Created: 9/10/2022 11:36:42 PM
 *  Author: Elwazeer
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

#include "../DIO/DIO.h"


typedef enum{
	INT0_pin,
	INT1_pin,
	INT2_pin
	}Interrupt_PIN_ID;


typedef enum{
	LOW_LEVEL,
	ANY_LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
	}Interrupt_Trigger_ID;

void Interrupt_Enable(Interrupt_PIN_ID interrupt);
void Interrupt_Disable(Interrupt_PIN_ID interrupt);

void Interrupt_TriggerEdge(Interrupt_PIN_ID interrupt  , Interrupt_Trigger_ID Edge);

void Interrupt_CallBack(Interrupt_PIN_ID interrupt , void(*localptr)(void));

#endif /* EX_INTERRUPT_H_ */