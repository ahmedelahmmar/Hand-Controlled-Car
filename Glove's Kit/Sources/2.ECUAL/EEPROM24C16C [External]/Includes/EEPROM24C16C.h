/*
 * EEPROM24C16C.h
 *
 *  Created on: 24 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_2_ECUAL_EEPROM24C16C__EXTERNAL__INCLUDES_EEPROM24C16C_H_
#define SOURCES_2_ECUAL_EEPROM24C16C__EXTERNAL__INCLUDES_EEPROM24C16C_H_

#include "Std_Types.h"
#include "Bit_Math.h"
#include "I2C.h"

void EEPROM24C16C_voidInit(void);
void EEPROM24C16C_voidWriteByte(u8 address, u8 data);
u8 EEPROM24C16C_u8ReadByte(u8 address);

#endif /* SOURCES_2_ECUAL_EEPROM24C16C__EXTERNAL__INCLUDES_EEPROM24C16C_H_ */
