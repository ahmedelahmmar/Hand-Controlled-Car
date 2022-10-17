/*
 * Buzzer.c
 *
 *  Created on: 27 Aug 2022
 *      Author: yabul
 */
#include "Buzzer.h"
#include "DIO.h"

void Buzzer_voidInit(void)
{
	DIO_voidconfigureChannel(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);
}
void Buzzer_voidOn(void)
{
	DIO_voidWRITEChannel(DIO_PORTA,DIO_PIN3,DIO_HIGH);
}
void Buzzer_voidOff(void)
{
	DIO_voidWRITEChannel(DIO_PORTA,DIO_PIN3,DIO_LOW);
}

