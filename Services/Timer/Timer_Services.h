/*
 * Timer_Services.h
 *
 * Created: 9/14/2022 3:48:26 PM
 *  Author: Elwazeer
 */ 


#ifndef TIMER_SERVICES_H_
#define TIMER_SERVICES_H_


#include "../../MCAL/Timer/Timer_Driver.h"


static void func_ICU(void);

void PWM_Init();
void PWM_Freq_KHZ(u16 freq);
void PWM_Freq_HZ(u16 freq);
void PWM_Duty(u16 duty);
void PWM_Measure(u32* pfreq , u8* pduty);

void Timer1_SetInterruptTime_ms(u16 time , void (*LocalFptr)(void));
void Timer1_SetInterruptTime_us(u16 time , void (*LocalFptr)(void));


#endif /* TIMER_SERVICES_H_ */