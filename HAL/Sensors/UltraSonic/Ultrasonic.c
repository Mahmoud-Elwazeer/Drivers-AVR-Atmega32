/*
 * Ultrasonic.c
 *
 * Created: 9/15/2022 10:23:23 PM
 *  Author: Elwazeer
 */ 

#include "Ultrasonic.h"

volatile u16 countt = 0 , tt1 , tt2 , flagg =0 ;

void Ultrasonic_Init(void)
{
	Timer1_Init(TIMER1_NORMAL_MODE , TIMER1_SCALER_8 , OCRA_DISCONNECTED , OCRB_DISCONNECTED);
	Timer1_OVF_SetCallBack(Func_OVF);
	Timer1_ICU_SetCallBack(Func_ICU);
	
}


u16 Ultrasonic_GetDistance(DIO_PIN_ID pin)
{
	flagg = 0;
	countt = 0;
	
	u16 Time;
	u16 Distance;
	
	DIO_SetPinValue( pin , HIGH);
	_delay_us(10);
	DIO_SetPinValue(pin , LOW);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	Timer1_OVF_InterruptEnable();
	
	while(flagg < 2);
	
	Time = (tt2 - tt1) + ((u32)countt * 65535);
	
	Distance = Time / 58;
	
	return Distance;
}


void Func_ICU(void)
{
	if (flagg == 0)
	{
		countt = 0;
		tt1 = ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flagg = 1;
	}
	else if (flagg == 1)
	{
		tt2 = ICR1;
		flagg = 2;
		Timer1_InputCaptureEdge(RISING);
		Timer1_ICU_InterruptDisable();
		Timer1_OVF_InterruptDisable();
	}
}

void Func_OVF(void)
{
	countt++;
}