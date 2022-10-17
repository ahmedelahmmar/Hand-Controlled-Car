/*
 * LED.h
 *
 *  Created on: 27 Aug 2022
 *      Author: yabul
 */

#ifndef SOURCES_2_ECUAL_LED_INCLUDES_LED_H_
#define SOURCES_2_ECUAL_LED_INCLUDES_LED_H_

#include "DIO.h"
#include "LED_Types.h"


void LED_voidInit(void);
void LED_voidLedOn(LED_ledsId_t);
void LED_voidLedOff(LED_ledsId_t);
void LED_voidLEDToggle(LED_ledsId_t LEDId);
void LED_voidFLASH(LED_ledsId_t LEDId);

#endif /* SOURCES_2_ECUAL_LED_INCLUDES_LED_H_ */
