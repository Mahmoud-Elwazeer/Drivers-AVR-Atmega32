/*
 * Keypad_Config.h
 *
 * Created: 10/18/2022 7:41:14 PM
 *  Author: Elwazeer
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "../../MCAL/DIO/DIO.h"


/******** All 4-pins in the same Port and another 4 in another port **********/
/*************** (OUTPUT IN DIO_CONFIG) **********/
#define FIRST_OUT_Pin        PIND0

/*************** (INPUT_PULL_UP IN DIO_CONFIG) **********/
#define FIRST_INP_Pin        PIND4

#define ROW              4
#define COLUMN           4

#define DEFAULT_KEY       '.'




#endif /* KEYPAD_CONFIG_H_ */