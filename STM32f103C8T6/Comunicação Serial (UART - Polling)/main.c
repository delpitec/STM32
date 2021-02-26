/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include <stdint.h> // uint8_t ....
#include <stdio.h>  // sprintf()
#include <string.h> // tratamento de string

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
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


  // String que limpa a tela do terminal e cursor na posicao 1x1
  const uint8_t CLRSCR[] = "\033[0H\033[0J";

  // Buffer para envio de dados
  uint8_t DadoTX[200] = {0};

  // Buffer para recebimento de dados
  uint8_t DadoRX[1] = {0};


  while (1){

	  // Recebe pela serial leitura dos botões da protoboard
	  HAL_UART_Receive(&huart1, DadoRX, 1, 100);

	  // Caso tenha recebido um dado, inverte o estado dos LEDs.
	  if(DadoRX[0] != 0){
		  switch(DadoRX[0]){
			  case '1': HAL_GPIO_TogglePin(LED_AZUL_GPIO_Port, LED_AZUL_Pin);        // Inverte valor do pino LED_AZUL
			  	  	    DadoRX[0] = 0;                                               // Zera caractere recebido
			  	  	  	break;
			  case '2': HAL_GPIO_TogglePin(LED_VERDE_GPIO_Port, LED_VERDE_Pin);		 // Inverte valor do pino LED_VERDE
						DadoRX[0] = 0; 												 // Zera caractere recebido
						break;
			  case '3': HAL_GPIO_TogglePin(LED_AMARELO_GPIO_Port, LED_AMARELO_Pin);	 // Inverte valor do pino LED_AMARELO
					    DadoRX[0] = 0; 												 // Zera caractere recebido
					    break;
			  case '4': HAL_GPIO_TogglePin(LED_VERMELHO_GPIO_Port, LED_VERMELHO_Pin);// Inverte valor do pino LED_VERMELHO
			  	  	  	DadoRX[0] = 0;  	  	  	  	  	  	  	  	  	  	  	 // Zera caractere recebido
						break;
		  }

	  }


	  // Envia pela serial o caractere para limpar a tela do terminal
	  HAL_UART_Transmit(&huart1, (unsigned char *)CLRSCR, strlen((const char *)CLRSCR), 100);

	  // Atualiza tela do terminal com os valores
	  sprintf((char *)DadoTX,
	  	    "Estados dos LEDS:\n\r1 - Led Azul    : %d \n\r2 - Led Verde   : %d \n\r3 - Led Amarelo : %d \n\r4 - Led Vermelho: %d\n\n\rEstados dos Botoes:\n\rBotao 5: %d\n\rBotao 6: %d\n\n\r",
	  	     HAL_GPIO_ReadPin(LED_AZUL_GPIO_Port, LED_AZUL_Pin),HAL_GPIO_ReadPin(LED_VERDE_GPIO_Port, LED_VERDE_Pin),
	  		 HAL_GPIO_ReadPin(LED_AMARELO_GPIO_Port, LED_AMARELO_Pin),HAL_GPIO_ReadPin(LED_VERMELHO_GPIO_Port, LED_VERMELHO_Pin),
	  		 HAL_GPIO_ReadPin(BOTAO_V_GPIO_Port, BOTAO_V_Pin), HAL_GPIO_ReadPin(BOTAO_VI_GPIO_Port, BOTAO_VI_Pin));

	  // Envia pela serial texto atualizado
	  HAL_UART_Transmit(&huart1, DadoTX, strlen((const char *)DadoTX), 500);




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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_AMARELO_Pin|LED_VERDE_Pin|LED_AZUL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_VERMELHO_GPIO_Port, LED_VERMELHO_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_AMARELO_Pin LED_VERDE_Pin LED_AZUL_Pin */
  GPIO_InitStruct.Pin = LED_AMARELO_Pin|LED_VERDE_Pin|LED_AZUL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_VERMELHO_Pin */
  GPIO_InitStruct.Pin = LED_VERMELHO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_VERMELHO_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BOTAO_VI_Pin BOTAO_V_Pin */
  GPIO_InitStruct.Pin = BOTAO_VI_Pin|BOTAO_V_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

#ifdef  USE_FULL_ASSERT
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
