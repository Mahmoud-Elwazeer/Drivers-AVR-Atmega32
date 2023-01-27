/*
 * I2C_config.h
 *
 * Created: 12/8/2022 4:03:18 PM
 *  Author: Elwazeer
 */ 


#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_



//TWPS Values prescaler
#define I2C_TWPS_1   0
#define I2C_TWPS_4   1
#define I2C_TWPS_16  2
#define I2C_TWPS_64  3


/*To calculate SCL use Equation:
 * SCL = F_CPU /(16 + (2*TWBR*(4^TWPS)))
 */

#define I2C_TWBR_VALUE			   72
#define I2C_TWPS_VALUE             I2C_TWPS_1
 
 

#endif /* I2C CONFIG_H_ */