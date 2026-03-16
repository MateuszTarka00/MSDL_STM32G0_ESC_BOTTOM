/*
 * safetyCircuit.h
 *
 *  Created on: 16 mar 2026
 *      Author: mateo
 */

#ifndef INC_SAFETYCIRCUIT_H_
#define INC_SAFETYCIRCUIT_H_

#include "main.h"

typedef enum
{
	STOP_INLET,
	COMB_BOARD_RIGHT,
	COMB_BOARD_LEFT,
	HANDRAIL_INLET_LEFT,
	HANDRAIL_INLET_RIGHT,
	BROKEN_STEP_CONTACT,
	CHAIN_CONTACT_LEFT,
	CHAIN_CONTACT_RIGHT,
	SAFETY_CIRCUIT_ERROR
}SafetyCircuitPoint;

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin;
}SafetyCircuitPoints;

#endif /* INC_SAFETYCIRCUIT_H_ */
