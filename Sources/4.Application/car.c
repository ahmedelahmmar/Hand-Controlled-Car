/*
 * main.c
 *
 *  Created on: Oct 12, 2022
 *      Author: 4hmed
 */
#include "avr/interrupt.h"

// MCAL Includes
#include "TIMER.h"
#include "UART.h"

// HAL Includes
#include "LCD.h"
#include "MG995.h"
#include "DC_Motor.h"

#define FORWARD						'f'
#define FORWARD_FULL_SPEED			'F'
#define BACKWARD					'b'
#define BRAKE						'B'
#define RIGHT						'r'
#define STRAIGHT					's'
#define LEFT						'l'

uint8_t recievedCommand;

int main(void)
{
	UART_voidInit(9600, RX, DATABITS_8, STOPBITS_1, NO_PARITY);

	DC_Motor_voidInit();
	MG995_Init();
	MG995_Start();


	while (True)
	{
		recievedCommand = UART_voidRecieveByte();

		switch (recievedCommand)
		{
		case FORWARD:
			DC_Motor_voidStart(MOTOR_A, CW);
			DC_Motor_voidStart(MOTOR_B, CCW);
			break;

		case FORWARD_FULL_SPEED:
			break;

		case BACKWARD:
			break;

		case BRAKE:
			break;

		case RIGHT:
			break;

		case STRAIGHT:
			break;

		case LEFT:
			break;

		default: break;
		}
	}
}
