/*
 * DC_Motor.c
 *
 *  Created on: 14 Sep 2022
 *      Author: yabul
 */
#include "DC_Motor.h"
#include "DIO.h"
#include "DIO_REG.h"
#include "DIO_TYPES.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include <util/delay.h>

void DC_Motor_voidInit(void)
{
	// Configure Motor control pins as outputs

	//Motor A
	DIO_voidconfigureChannel(DIO_PORTD,DIO_PIN4,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN3,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN4,DIO_OUTPUT);

	//Motor B
	DIO_voidconfigureChannel(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN5,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN6,DIO_OUTPUT);

	// Make sure Motor is stop EN = 0
	//Enable 1
	DIO_voidWRITEChannel(DIO_PORTD,DIO_PIN4,DIO_LOW);
	//Enable 2
	DIO_voidWRITEChannel(DIO_PORTD,DIO_PIN5,DIO_LOW);
}

void DC_Motor_voidStart(DC_MOTOR_T DCtype,DC_DIR_T DCdir)
{
	if (DCtype == DC_MOTOR_A)
	{
		if (DCdir == DIR_CW)
		{
			SET_BIT(DIO_PORTC_REG,DIO_PIN3);
			CLEAR_BIT(DIO_PORTC_REG,DIO_PIN4);
		}
		else
		{
			CLEAR_BIT(DIO_PORTC_REG,DIO_PIN3);
			SET_BIT(DIO_PORTC_REG,DIO_PIN4);
		}
		SET_BIT(DIO_PORTD_REG,DIO_PIN4);
	}
	else if (DCtype == DC_MOTOR_B)
	{
		if (DCdir == DIR_CW)
		{
			SET_BIT(DIO_PORTC_REG,DIO_PIN5);
			CLEAR_BIT(DIO_PORTC_REG,DIO_PIN6);
		}
		else
		{
			CLEAR_BIT(DIO_PORTC_REG,DIO_PIN5);
			SET_BIT(DIO_PORTC_REG,DIO_PIN6);
		}
		SET_BIT(DIO_PORTD_REG,DIO_PIN5);
	}
}
void DC_Motor_voidStop(DC_MOTOR_T DCtype)
{
	if (DCtype == DC_MOTOR_A)
	{
		//CLEAR EN1 PIN
		CLEAR_BIT(DIO_PORTD_REG,DIO_PIN4);
		//wait till motor stop
		//_delay_ms(3000);
		_delay_ms(3000);
	}
	else if (DCtype == DC_MOTOR_B)
	{
		//CLEAR EN1 PIN
		CLEAR_BIT(DIO_PORTD_REG,DIO_PIN5);
		//wait till motor stop
		//_delay_ms(3000);
		_delay_ms(3000);
	}

}


