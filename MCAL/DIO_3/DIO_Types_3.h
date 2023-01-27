/*
 * AVR_INPUT_OUTPUT.h
 *
 * Created: 7/30/2022 7:59:23 PM
 *  Author: Elwazeer
 */ 



#ifndef AVR_INPUT_OUTPUT_H_
#define AVR_INPUT_OUTPUT_H_

#include "../../Std_types.h"

#define A         (vu8*)0x39
#define B         (vu8*)0x36
#define C         (vu8*)0x33
#define D         (vu8*)0x30

typedef enum{
	LOW, 
	HIGH
	}DIO_3_Value;
	
typedef enum{
	OUTPUT,
	INPUT,
	INPUT_PULL_UP
}DIO_3_Direction;

typedef enum{
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7
}DIO_3_Pin_ID;



#endif /* AVR_INPUT_OUTPUT_H_ */