/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */
uint8_t SEG_Digit[]={
						 //0GFEDCBA
	0x40      ,//01000000 //0
	0x79			,//01111001 //1
	0x24      ,//00100100 //2
	0x30			,//00110000 //3
	0x19			,//00011001 //4
	0x12			,//00010010 //5
	0x02			,//00000010 //6
	0x78			,//01111000 //7
	0x00			,//00000000 //8
	0x10			 //00010000 //9
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void SEG_Decoder(int number);
void SEG_Display(int num);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
	int count=8888;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		if(count <= 9999){
			count = count + 1;
		}
		else{
			count = 0;
		}
		SEG_Display(count);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, G1_Pin|G2_Pin|G3_Pin|G4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, A_Pin|B_Pin|C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : G1_Pin G2_Pin G3_Pin G4_Pin
                           A_Pin B_Pin C_Pin D_Pin
                           E_Pin F_Pin G_Pin */
  GPIO_InitStruct.Pin = G1_Pin|G2_Pin|G3_Pin|G4_Pin
                          |A_Pin|B_Pin|C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void SEG_Decoder(int number){
	uint8_t digit = SEG_Digit[number];
	//0GFEDCBA   
	//SEG_A
	if((digit & 0x01) == 0x01){
		HAL_GPIO_WritePin(GPIOA, A_Pin, 1);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, A_Pin, 0);
	}
	//SEG_B
	if((digit & 0x02) == 0x02){
		HAL_GPIO_WritePin(GPIOA, B_Pin, 1);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, B_Pin, 0);
	}
	//SEG_C
	if((digit & 0x04) == 0x04){
		HAL_GPIO_WritePin(GPIOA, C_Pin, 1);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, C_Pin, 0);
	}
	//SEG_D
	if((digit & 0x08) == 0x08){
		HAL_GPIO_WritePin(GPIOA, D_Pin, 1);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, D_Pin, 0);
	}
	//SEG_E
	if((digit & 0x10) == 0x10){
		HAL_GPIO_WritePin(GPIOA, E_Pin, 1);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, E_Pin, 0);
	}
	//SEG_F
	if((digit & 0x20) == 0x20){
		HAL_GPIO_WritePin(GPIOA, F_Pin, 1);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, F_Pin, 0);
	}
	//SEG_G
	if((digit & 0x40) == 0x40){
		HAL_GPIO_WritePin(GPIOA, G_Pin, 1);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, G_Pin, 0);
	}
};

void SEG_Display(int num){
	int thousands = num/1000;
	int hundreds  = num%1000/100;
	int tens  		=	num%100/10;
	int ones			= num%10;
	SEG_Decoder(thousands);
	HAL_GPIO_WritePin(GPIOA, G1_Pin, 1);
	HAL_Delay(5);
	HAL_GPIO_WritePin(GPIOA, G1_Pin, 0);
	
	SEG_Decoder(hundreds);
	HAL_GPIO_WritePin(GPIOA, G2_Pin, 1);
	HAL_Delay(5);
	HAL_GPIO_WritePin(GPIOA, G2_Pin, 0);
	
	SEG_Decoder(tens);
	HAL_GPIO_WritePin(GPIOA, G3_Pin, 1);
	HAL_Delay(5);
	HAL_GPIO_WritePin(GPIOA, G3_Pin, 0);
	
	SEG_Decoder(ones);
	HAL_GPIO_WritePin(GPIOA, G4_Pin, 1);
	HAL_Delay(5);
	HAL_GPIO_WritePin(GPIOA, G4_Pin, 0);
};
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
