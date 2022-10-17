/*
 * EEPROM.c
 *
 *  Created on: 24 Sep 2022
 *      Author: yabul
 */
#include "../../EEPROM [MCAL]/Includes/EEPROM.h"

#include "I2C.h"
void EEPROM_voidInit(void)
{
	I2C_MasterInit();
	I2C_StartCondition();
	//I2C_SlaveInit();
	EEPROM_EEARH_REG = EEPROM_EEARH_REG & EEARH_MASK;

}
void EEPROM_voidWriteByte(u8 page,u8 address, u8 data)
{

}
u8 EEPROM_u8ReadByte(u8 page, u8 address)
{

}

