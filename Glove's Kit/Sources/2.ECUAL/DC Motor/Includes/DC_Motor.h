/*
 * DC_Motor.h
 *
 *  Created on: 14 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_2_ECUAL_DC_MOTOR_INCLUDES_DC_MOTOR_H_
#define SOURCES_2_ECUAL_DC_MOTOR_INCLUDES_DC_MOTOR_H_
#include "DC_Direction.h"
#include "DC_MOTOR_Type.h"

void DC_Motor_voidInit(void);
void DC_Motor_voidStart(DC_MOTOR_T DCtype,DC_DIR_T DCdir);
void DC_Motor_voidStop(DC_MOTOR_T DCtype);


#endif /* SOURCES_2_ECUAL_DC_MOTOR_INCLUDES_DC_MOTOR_H_ */
