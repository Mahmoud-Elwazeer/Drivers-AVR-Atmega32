/*
 * ADC_Services.c
 *
 * Created: 10/18/2022 8:23:16 PM
 *  Author: Elwazeer
 */ 


#include "ADC_Services.h"

u16 ADC_Read_Volt(ADC_Channel channel)
{
	
	ADC_StartConversion(channel);
	u16 adc = ADC_Read();
	
	/// volt in milli volt
	u16 volt = ((u32)5000*adc)/1024;
	
	return volt;
	
}
