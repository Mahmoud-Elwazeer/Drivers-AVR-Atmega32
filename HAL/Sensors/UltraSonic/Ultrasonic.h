/*
 * Ultrasonic.h
 *
 * Created: 9/15/2022 10:23:38 PM
 *  Author: Elwazeer
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../../../MCAL/DIO/DIO.h"
#include "../../../MCAL/Timer/Timer_Driver.h"
#include "../../../MCAL/Interrupt/Interrupt_Ex.h"

void Ultrasonic_Init(void);
u16 Ultrasonic_GetDistance(DIO_PIN_ID pin);
void Func_ICU(void);
void Func_OVF(void);

#endif /* ULTRASONIC_H_ */