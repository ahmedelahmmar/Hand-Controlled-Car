/*
 * KEYPAD.h
 *
 *  Created on: 2 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_2_ECUAL_KEYPAD_INCLUDE_KEYPAD_H_
#define SOURCES_2_ECUAL_KEYPAD_INCLUDE_KEYPAD_H_
#include "DIO.h"

void KEYPAD_voidInit(void);
void KEYPAD_RESET(void);
u8 KEYPAD_u8FindKey(void);

#endif /* SOURCES_2_ECUAL_KEYPAD_INCLUDE_KEYPAD_H_ */
