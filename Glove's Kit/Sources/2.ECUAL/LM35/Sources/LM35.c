/*
 * LM35.c
 *
 *  Created on: 9 Sep 2022
 *      Author: yabul
 */
#include "LM35.h"
#include "ADC.h"

void LM35_voidInit(void)
{
	//ADC_voidInit();
	ADC_voidInit(ADC_AVCC);
}
u8 LM35_u8TempRead(void)
{
	f64 volt= ADC_f64ReadVolts_mv(ADC_ADC1);
	u16 Temp = ((volt)/10);
	return Temp;
}

