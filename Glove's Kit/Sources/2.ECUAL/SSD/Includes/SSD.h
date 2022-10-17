/*
 * SSD.h
 *
 *  Created on: 30 Aug 2022
 *      Author: yabul
 */

#ifndef SOURCES_2_ECUAL_SSD_INCLUDES_SSD_H_
#define SOURCES_2_ECUAL_SSD_INCLUDES_SSD_H_
#include "Std_Types.h"

#define SSD_MASK (0b00001111)

void SSD_voidInit(void);
void SSD_voidDisplayNum(u8 num);
void SSD_CountDisplayNum(u8 num);
void SSD_voidDelayWDisplay_ms(u8 num, u32 delay);



#endif /* SOURCES_2_ECUAL_SSD_INCLUDES_SSD_H_ */
