/*
 * EEPROM_Reg.h
 *
 *  Created on: 24 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_2_ECUAL_EEPROM__MCAL__INCLUDES_EEPROM_REG_H_
#define SOURCES_2_ECUAL_EEPROM__MCAL__INCLUDES_EEPROM_REG_H_

#define EEPROM_EEARH_REG	(*(u8*)0x3F)
#define EEPROM_EEARL_REG	(*(u8*)0x3E)
#define EEPROM_EEDR_REG		(*(u8*)0x3D) //EEPROM ADDRESS REGISTER LOW BYTE
#define EEPROM_EECR_REG		(*(u8*)0x3C) //EEPROM DATA REGISTER
#define EEARH_MASK			(0x03)


#endif /* SOURCES_2_ECUAL_EEPROM__MCAL__INCLUDES_EEPROM_REG_H_ */