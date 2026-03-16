/*
 * safetyCircuit.c
 *
 *  Created on: 16 mar 2026
 *      Author: mateo
 */


#include "safetyCircuit.h"

#define BROKEN_CIRCUIT_POINT		0
#define NUMBER_OF_CIRCUITS_POINTS	8

bool getSafetyCircuitState()
{
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);
}

const SafetyCircuitPoints safetyCircuitPoints[NUMBER_OF_CIRCUITS_POINTS] =
{
	{SAFETY_C1_GPIO_Port, SAFETY_C1_Pin},
	{SAFETY_C2_GPIO_Port, SAFETY_C2_Pin},
	{SAFETY_C3_GPIO_Port, SAFETY_C3_Pin},
	{SAFETY_C4_GPIO_Port, SAFETY_C4_Pin},
	{SAFETY_C5_GPIO_Port, SAFETY_C5_Pin},
	{SAFETY_C6_GPIO_Port, SAFETY_C6_Pin},
	{SAFETY_C7_GPIO_Port, SAFETY_C7_Pin},
	{SAFETY_C8_GPIO_Port, SAFETY_C8_Pin},
};

SafetyCircuitPoint checkBrokenSafetyCircuitPoint(void)
{
	for(uint8_t i = 0; i < NUMBER_OF_CIRCUITS_POINTS; ++i)
	{
		if(HAL_GPIO_ReadPin(safetyCircuitPoints[i].port, safetyCircuitPoints[i].pin) == BROKEN_CIRCUIT_POINT)
		{
			return i;
		}
	}
	return SAFETY_CIRCUIT_ERROR;
}
