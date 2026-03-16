/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cmsis_os2.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SAFETY_END_Pin GPIO_PIN_13
#define SAFETY_END_GPIO_Port GPIOB
#define CHECK_HUMAN_DOWN_Pin GPIO_PIN_8
#define CHECK_HUMAN_DOWN_GPIO_Port GPIOA
#define SAFETY_C1_Pin GPIO_PIN_9
#define SAFETY_C1_GPIO_Port GPIOA
#define SAFETY_C2_Pin GPIO_PIN_6
#define SAFETY_C2_GPIO_Port GPIOC
#define SAFETY_C3_Pin GPIO_PIN_7
#define SAFETY_C3_GPIO_Port GPIOC
#define SAFETY_C4_Pin GPIO_PIN_10
#define SAFETY_C4_GPIO_Port GPIOA
#define CAN_FAULT_Pin GPIO_PIN_15
#define CAN_FAULT_GPIO_Port GPIOA
#define CAN_OK_Pin GPIO_PIN_0
#define CAN_OK_GPIO_Port GPIOD
#define SAFETY_C5_Pin GPIO_PIN_3
#define SAFETY_C5_GPIO_Port GPIOD
#define SAFETY_C6_Pin GPIO_PIN_3
#define SAFETY_C6_GPIO_Port GPIOB
#define SAFETY_C7_Pin GPIO_PIN_4
#define SAFETY_C7_GPIO_Port GPIOB
#define SAFETY_C8_Pin GPIO_PIN_5
#define SAFETY_C8_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
typedef enum
{
	FALSE,
	TRUE
}bool;

extern osThreadId_t canResponseTHandle;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
