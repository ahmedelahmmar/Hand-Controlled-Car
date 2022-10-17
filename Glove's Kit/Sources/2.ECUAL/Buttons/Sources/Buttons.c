/*
 * Buttons.c
 *
 *  Created on: 27 Aug 2022
 *      Author: yabul
 */
#include "Button.h"
#include "Button_Types.h"
#include "DIO.h"
void BUTTONS_voidInit(void){
	DIO_voidconfigureChannel(DIO_PORTB, DIO_PIN0,DIO_INPUT);
	DIO_voidconfigureChannel(DIO_PORTD, DIO_PIN6,DIO_INPUT);
	DIO_voidconfigureChannel(DIO_PORTD, DIO_PIN2,DIO_INPUT);
}
button_butStatus_t BUTTONS_udtButtonStatus(button_buttonId_t id)
{
	button_butStatus_t localstatus;
	switch (id)
	{
	case Button0:
		if (DIO_voidREADChannel(DIO_PORTB,DIO_PIN0))
		{
			localstatus = PRESSED;
		}
		else
		{
			localstatus = RELEASED;
		}
		break;

	case Button1:
		if (DIO_voidREADChannel(DIO_PORTD, DIO_PIN6))
		{
			localstatus = PRESSED;
		}
		else
		{
			localstatus = RELEASED;
		}
		break;

	case Button2:
		if (DIO_voidREADChannel(DIO_PORTD, DIO_PIN2))
		{
			localstatus = PRESSED;
		}
		else
		{
			localstatus = RELEASED;
		}
		break;
	}
	return localstatus;
}

