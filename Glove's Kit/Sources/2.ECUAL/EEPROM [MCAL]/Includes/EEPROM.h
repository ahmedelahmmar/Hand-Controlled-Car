/*
 * EEPROM.h
 *
 *  Created on: 24 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_2_ECUAL_EEPROM__MCAL__INCLUDES_EEPROM_H_
#define SOURCES_2_ECUAL_EEPROM__MCAL__INCLUDES_EEPROM_H_
#include "Std_Types.h"
#include "Bit_Math.h"
#include "I2C.h"

#include "../../EEPROM [MCAL]/Includes/EEPROM_Reg.h"

void EEPROM_voidInit(void);
void EEPROM_voidWriteByte(u8 page,u8 address, u8 data);
u8 EEPROM_u8WriteByte(u8 page, u8 address);


#endif /* SOURCES_2_ECUAL_EEPROM__MCAL__INCLUDES_EEPROM_H_ */
