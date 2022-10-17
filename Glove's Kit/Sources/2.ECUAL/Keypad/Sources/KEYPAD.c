/*
 * KEYPAD.c
 *
 *  Created on: 2 Sep 2022
 *      Author: yabul
 */
#include "KEYPAD.h"
#include "KEYPAD_Types.h"

u8 KEYPAD_Layout[4][4]=
{
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'*','0','#','D'}
};

void KEYPAD_voidInit(void)
{
	//Configure rows
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN0,DIO_INPUT);
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN1,DIO_INPUT);
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN2,DIO_INPUT);
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN3,DIO_INPUT);

	//Configure columns
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN4,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN5,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN6,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);

	//Write in each column zeros
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN4,DIO_LOW);
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN5,DIO_LOW);
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN6,DIO_LOW);
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);

	DIO_voidPULLUpEnable(DIO_PORTC,DIO_PIN0);
	DIO_voidPULLUpEnable(DIO_PORTC,DIO_PIN1);
	DIO_voidPULLUpEnable(DIO_PORTC,DIO_PIN2);
	DIO_voidPULLUpEnable(DIO_PORTC,DIO_PIN3);
}
void KEYPAD_RESET(void)
{
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN4,DIO_LOW);
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN5,DIO_LOW);
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN6,DIO_LOW);
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);
}
static boolean KEYPAD_PRESSED(void)
{
	if (
			DIO_voidREADChannel(DIO_PORTC,DIO_PIN0) == DIO_LOW ||
			DIO_voidREADChannel(DIO_PORTC,DIO_PIN1) == DIO_LOW ||
			DIO_voidREADChannel(DIO_PORTC,DIO_PIN2) == DIO_LOW ||
			DIO_voidREADChannel(DIO_PORTC,DIO_PIN3) == DIO_LOW
	)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

static KP_ROW_T KEYPAD_FindRow(void)
{
	KP_ROW_T loc_ButtonRow = KP_NOROW;
	if (DIO_voidREADChannel(DIO_PORTC,DIO_PIN0)==DIO_LOW)
	{
		loc_ButtonRow = KP_ROW0;
	}
	else if  (DIO_voidREADChannel(DIO_PORTC,DIO_PIN1)==DIO_LOW)
	{
		loc_ButtonRow = KP_ROW1;
	}
	else if  (DIO_voidREADChannel(DIO_PORTC,DIO_PIN2)==DIO_LOW)
	{
		loc_ButtonRow = KP_ROW2;
	}
	else if  (DIO_voidREADChannel(DIO_PORTC,DIO_PIN3)==DIO_LOW)
	{
		loc_ButtonRow = KP_ROW3;
	}
	else
	{
		loc_ButtonRow = -1;
	}

	return loc_ButtonRow;
}
static KP_COL_T KEYPAD_FindCol(KP_ROW_T CurrentRow)
{
	KP_COL_T loc_ButtonCol = KP_NOCOL;
	// 0 1 1 1
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN4,DIO_LOW);
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN5,DIO_HIGH);
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN6,DIO_HIGH);
	DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN7,DIO_HIGH);

	if (KEYPAD_FindRow()== CurrentRow)
	{
		loc_ButtonCol = KP_COL0;
	}
	else
	{
		DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN4,DIO_HIGH);
		DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN5,DIO_LOW);
		DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN6,DIO_HIGH);
		DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN7,DIO_HIGH);
		if (KEYPAD_FindRow()== CurrentRow)
		{
			loc_ButtonCol = KP_COL1;
		}
		else
			DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN4,DIO_HIGH);
		DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN5,DIO_HIGH);
		DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN6,DIO_LOW);
		DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN7,DIO_HIGH);
		if (KEYPAD_FindRow()==CurrentRow)
		{
			loc_ButtonCol = KP_COL2;
		}
		else
		{
			DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN4,DIO_HIGH);
			DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN5,DIO_HIGH);
			DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN6,DIO_HIGH);
			DIO_voidWRITEChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);
			if (KEYPAD_FindRow()==CurrentRow)
			{
				loc_ButtonCol = KP_COL3;
			}
			else
			{
				loc_ButtonCol = KP_NOCOL;
			}
		}
	}
	return loc_ButtonCol;
}

u8 KEYPAD_u8FindKey(void)
{
	u8 loc_Key = 0;
	KP_ROW_T loc_Row = KP_NOROW;
	KP_COL_T loc_Col = KP_NOCOL;

	KEYPAD_RESET();
	//Check if Keypad is pressed
	if (KEYPAD_PRESSED()==TRUE)
	{
		//If yes find the pressed key's row
		loc_Row = KEYPAD_FindRow();
		//Find the pressed key's column
		loc_Col = KEYPAD_FindCol(loc_Row);
		//loc_key=KEYPAD_Layout[Row][Column]
		loc_Key = KEYPAD_Layout[loc_Row][loc_Col];
	}
	else
	{
		//Do Nothing
		loc_Key = 0xFF;
	}
	return loc_Key;
}
