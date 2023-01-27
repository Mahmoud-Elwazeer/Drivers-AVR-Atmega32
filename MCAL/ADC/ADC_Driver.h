/*
 * ADC_Driver.h
 *
 * Created: 8/15/2022 9:35:32 PM
 *  Author: Elwazeer
 */ 


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_


#include "../../ATMEGA32_REG.h"
#include "../../Std_types.h"
#include "../../BIT_Math.h"

typedef enum{
	ADC_AREF,
	ADC_AVCC,
	ADC_2_56V
	}ADC_VoltageReference;
	
typedef enum{
	ADC_SCALER_2,
	ADC_SCALER_2_,
	ADC_SCALER_4,
	ADC_SCALER_8_,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64_,
	ADC_SCALER_128
	}ADC_Scaler_Type;
	
typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
	}ADC_Channel;

void ADC_Init(ADC_VoltageReference reference , ADC_Scaler_Type scaler);
void ADC_StartConversion(ADC_Channel channel);
u16 ADC_Read(void);
u16 ADC_ReadChannel(ADC_Channel channel);
u8 ADC_ReadNOBlock(u16 *pdata);



#endif /* ADC_DRIVER_H_ */