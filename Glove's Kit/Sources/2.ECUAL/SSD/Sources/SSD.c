/*
 * SSD.c
 *
 *  Created on: 30 Aug 2022
 *      Author: yabul
 */
#include "Std_Types.h"
#include "SSD.h"
#include "DIO.h"
#include <util/delay.h>

void SSD_voidInit(void)
{
	//Enable configuration
	DIO_voidconfigureChannel(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);
	//Pins configuration
	DIO_voidconfigureChannel(DIO_PORTA,DIO_PIN4,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);


}
void SSD_voidDisplayNum(u8 num)
{
	u8 loc_secondDigit = (num%10)<<4;  //0000 0101  -> 0101 0000
	u8 loc_firstDigit = (num/10)<<4;   //0000 0010

	//Enable SSD 1 -> En1 = High
	DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN2,DIO_HIGH);
	//Disable SSD 2 -> En2 = Low
	DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN1,DIO_LOW);
	// Write First Digit
	DIO_voidWRITEChannelGroup(DIO_PORTA,loc_firstDigit, SSD_MASK);

	_delay_us(300);

	//Disable SSD 1 -> En1 = Low
	DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN2,DIO_LOW);
	//Enable SSD 2 -> En2 = High
	DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN1,DIO_HIGH);
	// Write Second Digit
	DIO_voidWRITEChannelGroup(DIO_PORTA,loc_secondDigit, SSD_MASK);

	_delay_us(300);

}
void SSD_CountDisplayNum(u8 num)
{
	u8 loc_secondDigit2 = (num%10)<<4;  //0000 0101  -> 0101 0000
	u8 loc_firstDigit2 = (num/10)<<4;   //0000 0010

	for (int i=0;i<=4;i++)
	{
		for (int j=0; j<=9; j++)
		{
			DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN2,DIO_HIGH);
			//Disable SSD 2 -> En2 = Low
			DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN1,DIO_LOW);
			// Write First Digit
			DIO_voidWRITEChannelGroup(DIO_PORTA,loc_firstDigit2, SSD_MASK);

			//_delay_us(500);
			_delay_ms(10);
			//Disable SSD 1 -> En1 = Low
			DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN2,DIO_LOW);
			//Enable SSD 2 -> En2 = High
			DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN1,DIO_HIGH);
			// Write Second Digit
			DIO_voidWRITEChannelGroup(DIO_PORTA,loc_secondDigit2, SSD_MASK);

			//_delay_us(500);
			_delay_ms(10);
		}
	}
}
void SSD_voidDelayWDisplay_ms(u8 num, u32 delay)
{
	for (u32 loc_counter=0; loc_counter<delay/2;loc_counter++)
	{
		SSD_voidDisplayNum(num);
	}
}
