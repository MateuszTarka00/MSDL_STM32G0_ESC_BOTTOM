/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "fdcan.h"
#include "canCommunication.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for mainTaskT */
osThreadId_t mainTaskTHandle;
const osThreadAttr_t mainTaskT_attributes = {
  .name = "mainTaskT",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 254 * 4
};
/* Definitions for canResponseT */
osThreadId_t canResponseTHandle;
const osThreadAttr_t canResponseT_attributes = {
  .name = "canResponseT",
  .priority = (osPriority_t) osPriorityBelowNormal7,
  .stack_size = 254 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void mainTask(void *argument);
void canResponse(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
	CAN_InitRTOS();
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of mainTaskT */
  mainTaskTHandle = osThreadNew(mainTask, NULL, &mainTaskT_attributes);

  /* creation of canResponseT */
  canResponseTHandle = osThreadNew(canResponse, NULL, &canResponseT_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_mainTask */
/**
  * @brief  Function implementing the mainTaskT thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_mainTask */
void mainTask(void *argument)
{
  /* USER CODE BEGIN mainTask */
	HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);
	HAL_FDCAN_Start(&hfdcan1);
  /* Infinite loop */
  for(;;)
  {
	  sendSensorStateEventTx();
    osDelay(100);
  }
  /* USER CODE END mainTask */
}

/* USER CODE BEGIN Header_canResponse */
/**
* @brief Function implementing the canResponseT thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_canResponse */
void canResponse(void *argument)
{
  /* USER CODE BEGIN canResponse */
  /* Infinite loop */
  for(;;)
  {
	CAN_Message_t msg;
	if(xQueueReceive(canRxQueue, &msg, portMAX_DELAY) == pdTRUE)
	{
		processMessage(&msg);
	}

  }
  /* USER CODE END canResponse */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

