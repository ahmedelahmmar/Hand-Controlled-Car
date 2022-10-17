/*
 * I2C_Reg.h
 *
 *  Created on: 24 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_1_MCAL_I2C_INCLUDES_I2C_REG_H_
#define SOURCES_1_MCAL_I2C_INCLUDES_I2C_REG_H_

#include "Std_Types.h"

#define I2C_TWDR_REG      		(*(volatile u8*)0x23)
#define I2C_TWAR_REG			(*(volatile u8*)0x22)
#define I2C_TWCR_REG			(*(volatile u8*)0x56)
#define I2C_TWSR_REG			(*(volatile u8*)0x21)
#define I2C_TWBR_REG			(*(volatile u8*)0x20)

#define I2C_START_COND					(1<<5)
#define I2C_STOP_COND					(1<<4)
#define I2C_ENABLE						(1<<2)
#define I2C_INTERRUPT_FLAG				(1<<7)
#define I2C_ENABLE_ACK					(1<<6)
#define I2C_INTERRUPT_FLAG_BIT_NO		 (7)
#define I2C_SLAVE_RESPONSE_BIT_NO		 (0)

#endif /* SOURCES_1_MCAL_I2C_INCLUDES_I2C_REG_H_ */
