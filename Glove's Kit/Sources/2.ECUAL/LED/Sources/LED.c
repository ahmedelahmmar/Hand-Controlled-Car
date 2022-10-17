/*
 * LED.c
 *
 *  Created on: 27 Aug 2022
 *      Author: yabul
 */
#include "LED.h"
#include "DIO.h"
#include <util/delay.h>

void LED_voidInit(void)
{
	DIO_voidconfigureChannel(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTC, DIO_PIN7, DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTD, DIO_PIN3, DIO_OUTPUT);
}

void LED_voidLedOn(LED_ledsId_t ledId)
{
	switch (ledId)
	{
	case LED0:
		DIO_voidWRITEChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		break;

	case LED1:
			DIO_voidWRITEChannel(DIO_PORTC, DIO_PIN7, DIO_HIGH);
			break;

	case LED2:
			DIO_voidWRITEChannel(DIO_PORTD, DIO_PIN3, DIO_HIGH);
			break;
	}
}

void LED_voidLedOff(LED_ledsId_t ledId)
{
	switch (ledId)
	{
	case LED0:
		DIO_voidWRITEChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		break;

	case LED1:
			DIO_voidWRITEChannel(DIO_PORTC, DIO_PIN7, DIO_LOW);
			break;

	case LED2:
			DIO_voidWRITEChannel(DIO_PORTD, DIO_PIN3, DIO_LOW);
			break;
	}
}

void LED_voidLEDToggle(LED_ledsId_t LEDId)
{
	switch (LEDId)
	{
	case LED0:
		DIO_voidFlipChannel(DIO_PORTC,DIO_PIN2);
		break;
	case LED1:
		DIO_voidFlipChannel(DIO_PORTC,DIO_PIN7);
		break;
	case LED2:
		DIO_voidFlipChannel(DIO_PORTD,DIO_PIN3);
		break;
	}
}

void LED_voidFLASH(LED_ledsId_t LEDId){
	switch (LEDId)
		{
		case LED0:
			LED_voidLedOn(LED0);
			_delay_ms(500);
			LED_voidLedOff(LED0);
			_delay_ms(500);
			LED_voidLedOn(LED0);
			_delay_ms(100);
			LED_voidLedOff(LED0);
			_delay_ms(100);
			LED_voidLedOn(LED0);
			_delay_ms(500);
			LED_voidLedOff(LED0);
			_delay_ms(500);
			LED_voidLedOn(LED0);
			_delay_ms(100);
			LED_voidLedOff(LED0);
			_delay_ms(100);
			LED_voidLedOn(LED0);
			_delay_ms(200);
			LED_voidLedOff(LED0);
			_delay_ms(200);
			break;
		case LED1:
			LED_voidLedOn(LED1);
			_delay_ms(500);
			LED_voidLedOff(LED1);
			_delay_ms(500);
			LED_voidLedOn(LED1);
			_delay_ms(100);
			LED_voidLedOff(LED1);
			_delay_ms(100);
			LED_voidLedOn(LED1);
			_delay_ms(500);
			LED_voidLedOff(LED1);
			_delay_ms(500);
			LED_voidLedOn(LED1);
			_delay_ms(100);
			LED_voidLedOff(LED1);
			_delay_ms(100);
			LED_voidLedOn(LED1);
			_delay_ms(200);
			LED_voidLedOff(LED1);
			_delay_ms(200);
			break;
		case LED2:
			LED_voidLedOn(LED2);
			_delay_ms(500);
			LED_voidLedOff(LED2);
			_delay_ms(500);
			LED_voidLedOn(LED2);
			_delay_ms(100);
			LED_voidLedOff(LED2);
			_delay_ms(100);
			LED_voidLedOn(LED2);
			_delay_ms(500);
			LED_voidLedOff(LED2);
			_delay_ms(500);
			LED_voidLedOn(LED2);
			_delay_ms(100);
			LED_voidLedOff(LED2);
			_delay_ms(100);
			LED_voidLedOn(LED2);
			_delay_ms(200);
			LED_voidLedOff(LED2);
			_delay_ms(200);
			break;
		}
}
