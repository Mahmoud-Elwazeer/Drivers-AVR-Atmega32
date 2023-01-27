/*
 * SPI_Config.h
 *
 * Created: 11/27/2022 4:06:47 PM
 *  Author: Elwazeer
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


/******************************* SPI Configuration ******************/
#define  SPEED_MODE         NORMAL_SPEED
#define  SCK_F              SCK_F_div_4

/********************speed mode*************************/
#define NORMAL_SPEED      0
#define DOUBLE_SPEED      1


/*******************SCK_F *****************************/
#define  SCK_F_div_4         0  
#define  SCK_F_div_16        1
#define  SCK_F_div_64        2
#define  SCK_F_div_128       3





#endif /* SPI_CONFIG_H_ */