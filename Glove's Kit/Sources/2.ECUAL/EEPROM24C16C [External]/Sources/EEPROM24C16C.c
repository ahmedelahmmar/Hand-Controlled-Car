/*
 * EEPROM24C16C.c
 *
 *  Created on: 24 Sep 2022
 *      Author: yabul
 */
#include "EEPROM24C16C.h"
#include <util/delay.h>

void EEPROM24C16C_voidInit(void)
{
	I2C_MasterInit();
}
void EEPROM24C16C_voidWriteByte(u8 address, u8 data)
{
	u8 loc_pageNo = (address/256);
	u8 loc_byteNo = (address%256);

	I2C_StartCondition();

	/*1010 0001 <<1  -> 0100 0010
	so to solve this make the mask 0101 0000 when shifted = 1010 0000*/


	I2C_Send_SlaveAddressWriteOperation(0x50|loc_pageNo);
	I2C_WriteByte(loc_byteNo);
	I2C_WriteByte(data);

	I2C_StopCondition();
	_delay_ms(10);
}
u8 EEPROM24C16C_u8ReadByte(u8 address)
{
	u8 loc_pageNo = (address/256);
	u8 loc_byteNo = (address%256);
	u8 loc_dataRead = 0;

	I2C_StartCondition();
	I2C_Send_SlaveAddressWriteOperation(0x50|loc_pageNo);
	I2C_WriteByte(loc_byteNo);

	I2C_RepeatedStartCondition();
	I2C_Send_SlaveAddressReadOperation(0x50|loc_pageNo);
	loc_dataRead=I2C_ReadByte();

	I2C_StopCondition();

	return loc_dataRead;
};

