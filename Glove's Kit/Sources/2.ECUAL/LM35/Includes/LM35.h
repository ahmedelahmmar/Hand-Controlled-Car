/*
 * LM35.h
 *
 *  Created on: 9 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_2_ECUAL_LM35_INCLUDES_LM35_H_
#define SOURCES_2_ECUAL_LM35_INCLUDES_LM35_H_
#include "ADC.h"
#include "Std_Types.h"

void LM35_voidInit(void);
u8 LM35_u8TempRead(void);

#endif /* SOURCES_2_ECUAL_LM35_INCLUDES_LM35_H_ */
