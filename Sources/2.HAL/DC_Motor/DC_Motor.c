/*
 * DC_Motor.c
 *
 *  Created on: Sep 14, 2022
 *      Author: 4hmed
 */

#include "DC_Motor.h"

void DC_Motor_voidInit(void)
{
	// Configure Motor pins as output
	DIO_voidConfig(DIO_PIN4, DIO_PORTD, DIO_OUTPUT);
	DIO_voidConfig(DIO_PIN7, DIO_PORTD, DIO_OUTPUT);

	DIO_voidConfig(DIO_PIN3, DIO_PORTC, DIO_OUTPUT);
	DIO_voidConfig(DIO_PIN4, DIO_PORTC, DIO_OUTPUT);
	DIO_voidConfig(DIO_PIN5, DIO_PORTC, DIO_OUTPUT);
	DIO_voidConfig(DIO_PIN6, DIO_PORTC, DIO_OUTPUT);

	// Make sure the motor is not rotating
	DIO_voidWrite(DIO_PIN4, DIO_PORTD, DIO_LOW);
	DIO_voidWrite(DIO_PIN5, DIO_PORTD, DIO_LOW);
}

void DC_Motor_voidStart(DC_Motor_Id_t motorId, DC_Motor_Direction_t direction)
{
	switch(motorId)
	{
	case MOTOR_A:

		if (direction == CW)
		{
			// set IN1 and clear IN2 then enable ENA
			DIO_voidWrite(DIO_PIN3, DIO_PORTC, DIO_LOW);
			DIO_voidWrite(DIO_PIN4, DIO_PORTC, DIO_HIGH);
		}
		else
		{
			// Set IN2 and clear IN1 then enable ENA
			DIO_voidWrite(DIO_PIN4, DIO_PORTC, DIO_LOW);
			DIO_voidWrite(DIO_PIN3, DIO_PORTC, DIO_HIGH);
		}

		DIO_voidWrite(DIO_PIN4, DIO_PORTD, DIO_HIGH);
		break;

	case MOTOR_B:

		if (direction == CW)
		{
			// set IN3 and clear IN4 then enable ENB
			DIO_voidWrite(DIO_PIN6, DIO_PORTC, DIO_LOW);
			DIO_voidWrite(DIO_PIN5, DIO_PORTC, DIO_HIGH);
		}
		else
		{
			// Set IN4 and clear IN3 then enable ENB
			DIO_voidWrite(DIO_PIN5, DIO_PORTC, DIO_LOW);
			DIO_voidWrite(DIO_PIN6, DIO_PORTC, DIO_HIGH);
		}

		DIO_voidWrite(DIO_PIN7, DIO_PORTD, DIO_HIGH);
		break;
	}
}

void DC_Motor_voidStop(DC_Motor_Id_t motorId)
{
	switch (motorId)
	{
	case MOTOR_A:

		// Clear ENA and wait for motor A to stop
		DIO_voidWrite(DIO_PIN4, DIO_PORTD, DIO_LOW);
		break;

	case MOTOR_B:

		// Clear ENB and wait for motor B to stop
		DIO_voidWrite(DIO_PIN5, DIO_PORTD, DIO_LOW);
		break;
	}
}

void DC_Motor_voidAdjustSpeed(uint8_t speed)
{

}
