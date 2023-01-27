/*
 * Sensor_LM35.c
 *
 * Created: 10/26/2022 12:58:30 PM
 *  Author: Elwazeer
 */ 


#include "Sensor_LM35.h"

u16 LM35_Read(ADC_Channel channel)
{
	return(ADC_Read_Volt(channel)/10);
}