/*
 * LCD_KEYPAD.c
 *
 * Created: 8/8/2022 10:31:50 PM
 *  Author: Elwazeer
 */ 

#include "KEYPAD_Driver.h"


static u8 key_array[ROW][COLUMN]={
									{'7' , '8' , '9' , '/'},
									{'4' , '5', '6' , '*'},
									{'1' , '2' , '3' , '-'},
									{'c' , '0' , '=' , '+'}
								 };



u8 keypad_Data(void)
{
	u8 r , c , key = DEFAULT_KEY;
	for(r = 0; r < ROW; r++)
	{
		DIO_SetPinValue(FIRST_OUT_Pin + r  , LOW);
		for(c = 0; c < COLUMN; c++)
		{
			if(!DIO_GetPinValue(FIRST_INP_Pin + c))
			{
				key = key_array[r][c];
				while(!DIO_GetPinValue(FIRST_INP_Pin + c));
			}
		}
		DIO_SetPinValue(FIRST_OUT_Pin + r  , HIGH);
	}
	return key;
}







