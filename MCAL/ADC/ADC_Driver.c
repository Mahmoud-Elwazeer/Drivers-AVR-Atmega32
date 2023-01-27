/*
 * ADC_Driver.c
 *
 * Created: 8/15/2022 9:35:01 PM
 *  Author: Elwazeer
 */ 


#include "ADC_Driver.h"

static u8 Read_flag = 0;

void ADC_Init(ADC_VoltageReference reference , ADC_Scaler_Type scaler)
{
	
	switch(reference)
	{
		case ADC_AREF:
		CLEAR_BIT(ADMUX , REFS0);
		CLEAR_BIT(ADMUX , REFS1);
		break;
		case ADC_AVCC:
		SET_BIT(ADMUX , REFS0);
		CLEAR_BIT(ADMUX , REFS1);
		break;
		case ADC_2_56V:
		SET_BIT(ADMUX , REFS0);
		SET_BIT(ADMUX , REFS1);
		break;
	}
	
	// Clock prescaler
	// ADPS2 , ADPS1 ,ADPS0
	ADCSRA &= 0xF8;  // 11111000
	scaler &= 0x07;
	ADCSRA |= scaler;
	
	// read adjust right
	CLEAR_BIT(ADMUX , ADLAR);
	
	// Enable
	SET_BIT(ADCSRA , ADEN);
	
}

void ADC_StartConversion(ADC_Channel channel)
{
	
	if (Read_flag == 0)
		{
			ADMUX &= 0xE0;
			ADMUX |= channel;
			
			// start conversion
			
			SET_BIT(ADCSRA ,ADSC);
			Read_flag = 1;
		}
}

u16 ADC_Read(void)
{

	// polling (busy wait)
	while(GET_BIT(ADCSRA ,ADSC));
	Read_flag = 0;
	return ADC;
	
}


u16 ADC_ReadChannel(ADC_Channel channel)
{
	ADMUX &= 0xE0;
	ADMUX |= channel;
	
	// start conversion
	
	SET_BIT(ADCSRA ,ADSC);
	// polling (busy wait)
	while(GET_BIT(ADCSRA ,ADSC));
	Read_flag = 0;
	return ADC;
}

u8 ADC_ReadNOBlock(u16 *pdata)
{
	// polling (periodic checking)
	if (GET_BIT(ADCSRA ,ADSC) == 0)
	{
		*pdata = ADC;
		Read_flag = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}