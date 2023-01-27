/*
 * UART_config.h
 *
 * Created: 10/5/2022 10:27:27 PM
 *  Author: Elwazeer
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


/******************************* UART Configuration ******************/
#define  SPEED_MODE         NORMAL_SPEED
#define  BUAD_RATE          BAUD_9600
#define  SYNCH_MODE         SYNCH
#define  PARITY_MODE        NO_PARITY
#define  N_DATA_BITS        _8_DATA_BITS
#define  N_STOP_BITS        ONE_STOP_BIT

/********************speed mode*************************/
#define NORMAL_SPEED      0
#define DOUBLE_SPEED      1


/*******************baud rate *****************************/
#define  BAUD_2400       2400
#define  BAUD_4800       4800
#define  BAUD_9600       9600
#define  BAUD_14400      14400
#define  BAUD_19200      19200
#define  BAUD_28800      28800


/*******************parity mode*************************/
#define NO_PARITY    0
#define EVEN_PARITY  1
#define ODD_PARITY   2

/*************** number of data bits********************/
#define  _5_DATA_BITS    5
#define  _6_DATA_BITS    6
#define  _7_DATA_BITS    7
#define  _8_DATA_BITS    8
#define  _9_DATA_BITS    9

/***************      sync mode*************************/
#define  SYNCH  0
#define  ASYNCH 1
/************    number of stop bits*****************/
#define  ONE_STOP_BIT   1
#define  TWO_STOP_BIT   2






#endif /* UART_CONFIG_H_ */