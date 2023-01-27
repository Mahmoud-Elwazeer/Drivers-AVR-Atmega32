/*
 * Timer_Services.c
 *
 * Created: 9/14/2022 3:34:10 PM
 *  Author: Elwazeer
 */ 

#include "Timer_Services.h"

volatile u16 ttime1 , ttime2 , t3 , flag =0;



void PWM_Init()
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE , TIMER1_SCALER_8 , OCRA_NON_INVERTING , OCRB_NON_INVERTING);
}

void PWM_Freq_KHZ(u16 freq)
{
	if (freq==0);
	else
	{
		u16 T_total = 1000 / freq;           // time micro second
		if(T_total >= 1)
		{
			ICR1 = T_total - 1;
		}
		else
			ICR1 = 0;
	}
}

void PWM_Freq_HZ(u16 freq)
{
	if (freq==0);
	else
	{
		u16 T_total = (u32)1000000 / freq;           // time micro second
		if(T_total >= 1)
		{
			ICR1 = T_total - 1;
		}
		else
		ICR1 = 0;
	}
}

void PWM_Duty(u16 duty)
{
	if (duty <= 100)              // max = 100%
	{
		u16 T_on = ((u32) duty * (ICR1 +1)) / 100;       //divide 100 convert percent
		if (T_on > 1)
			OCR1A = T_on - 1;
		else
			OCR1A = 0;
	}
}



void PWM_Measure(u32* pfreq , u8* pduty)
{
	u16 T_on , T_off;
	TCNT1= 0;
	Timer1_ICU_SetCallBack(func_ICU);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	flag = 0;
	
	while(flag < 3);
	T_on = ttime2 - ttime1;
	T_off = t3 - ttime2;
	
	*pduty = (T_on*100 / (T_on+T_off)) ;    // percent
	*pfreq = ((u32) 1000000 )/ ((u32)T_on +T_off);
	
}

static void func_ICU(void)
{
	if (flag == 0)
	{
		ttime1 = ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag = 1;
	}
	else if (flag == 1)
	{
		ttime2 = ICR1;
		Timer1_InputCaptureEdge(RISING);
		flag = 2;
	}
	else if (flag == 2)
	{
		t3 = ICR1;
		Timer1_ICU_InterruptDisable();
		flag = 3;
	}
}

// interrupt every one second

void Timer1_SetInterruptTime_ms(u16 time , void (*LocalFptr)(void))
{
	Timer1_Init(TIMER1_CTC_OCRA_TOP_MODE , TIMER1_SCALER_8 , OCRA_DISCONNECTED , OCRB_DISCONNECTED);
	// max time = 65 ms if you want more than 65 ms use othrt prscaler
	OCR1A = (time * 1000) - 1;       
	Timer1_OCA_SetCallBack(LocalFptr);
	Timer1_OCA_InterruptEnable();
	
}

void Timer1_SetInterruptTime_us(u16 time , void (*LocalFptr)(void))
{
	Timer1_Init(TIMER1_CTC_OCRA_TOP_MODE , TIMER1_SCALER_8 , OCRA_DISCONNECTED , OCRB_DISCONNECTED);
	OCR1A = time - 1;       // max time = 2^16
	Timer1_OCA_SetCallBack(LocalFptr);
	Timer1_OCA_InterruptEnable();
	
}