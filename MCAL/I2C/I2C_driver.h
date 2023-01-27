/*
 * I2C_driver.h
 *
 * Created: 12/8/2022 2:25:17 PM
 *  Author: Elwazeer
 */ 


#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include "../DIO/DIO.h"
#include "I2C_config.h"

//I2C Expected status
#define I2C_START_SENT                   0x08
#define I2C_REPEATED_START_SENT          0x10
#define I2C_SLA_W_SENT_WITH_ACK          0x18
#define I2C_SLA_W_SENT_WITHOT_ACK        0x20
#define I2C_DATA_SENT_WITH_ACK           0x28
#define I2C_DATA_SENT_WITHOUT_ACK        0x30
#define I2C_ARBITRATION_LOST             0x38
#define I2C_SLA_R_RECEIVED_WITH_ACK      0x40
#define I2C_SLA_R_RECEIVED_WITHOT_ACK    0x48
#define I2C_DATA_RECEIVED_WITH_ACK       0x50
#define I2C_DATA_RECEIVED_WITHOUT_ACK    0x58


void I2C_Init();
void I2C_StartCondition(void);
void I2C_StopCondition(void);
void I2C_WriteData(u8 data);
u8 I2C_ReadDataAck(void);
u8 I2C_ReadDataNAck(void);
u8 I2C_CheckStatus(void);

#endif /* I2C_DRIVER_H_ */