/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "flash_v1.0.h"
#include "lcd_v1.1.h"
#include <stdio.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define END_INICIAL 0x08006000 // Pag. 18 | Max (pag 63): 0x08018C00

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
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
  /* USER CODE BEGIN 2 */

#define TESTE_F



// Escreve 16 bits na FLASH
#if defined(TESTE_A)

	uint16_t valor = 0x0000;

	//apaga 1 pagina no endereço inicial
	FLASH_apaga(END_INICIAL, 1);

	//escreve o valor++ a cada 2 posições de endereço de memória (escreve toda a página - 0x400 = 1024 bytes)
	for (uint16_t index = 0;index < 0x400; index+=2 ){
		FLASH_escreve_16bits(END_INICIAL+index, &valor);
		valor++;
	}
#endif


// Escreve 32 bits na FLASH
#if defined(TESTE_B)

	uint32_t valor = 0x000A0000;

	//apaga 1 pagina no endereço inicial
	FLASH_apaga(END_INICIAL, 1);

	//escreve o valor++ a cada 4 posições de endereço de memória (escreve toda a página - 0x400 = 1024 bytes))
	for (uint32_t index = 0;index < 0x400; index+=4 ){
		FLASH_escreve_32bits(END_INICIAL+index, &valor);
		valor++;
	}

#endif


// Escreve String na FLASH
#if defined(TESTE_C)

	int8_t String[] = "Delpitec! Inscreva-se no melhor canal brasileiro de STM32 no YouTube";

	//apaga 1 pagina no endereço inicial
	FLASH_apaga(END_INICIAL, 1);

	//escreve String a partir do endereço de memória informado
	FLASH_escreve_string(END_INICIAL,String);


#endif


// Se END_INICIAL == 0xFFFF (livre, solicita dado (16 bits) para armazenar na FLASH
// Se END_INICIAL != 0xFFFF (ocupado, exibe valor (16 bits) e endereço armazenado na flash)
#if defined(TESTE_D)

	typedef enum{
		LER_DADO,
		SOLICITAR_DADO,
		GRAVAR_DADO,
		EXIBIR_DADO,
		MAIN_LOOP
	}TypedefEstado;

	TypedefEstado Estado = LER_DADO;
	uint16_t ValorLeitura = 0u;
	uint16_t ValorEscrita = 0u;
	int8_t   escreve_display[21] = {0};

	lcd_20x4_4bits_Init();

	while (Estado != MAIN_LOOP){

		switch (Estado){
			// Ao inicializar, verifica se endereço de memória está livre ou com informações gravadas
			case LER_DADO:
							FLASH_le_16bits(END_INICIAL, &ValorLeitura);
							if (ValorLeitura == 0xFFFF)
								Estado = SOLICITAR_DADO;
							else
								Estado = EXIBIR_DADO;
							break;
			// Usuário configura dado que deseja gravar na FLASH via display + teclado
			case SOLICITAR_DADO:
							while(Estado == SOLICITAR_DADO){
								if(!HAL_GPIO_ReadPin(TECLA_UP_GPIO_Port, TECLA_UP_Pin)){     // Tecla up (soma)
									ValorEscrita++;
									HAL_Delay(50);
								}

								if(!HAL_GPIO_ReadPin(TECLA_DOWN_GPIO_Port, TECLA_DOWN_Pin)){ // Tecla down (subtrai)
									ValorEscrita--;
									HAL_Delay(50);
								}
								if(!HAL_GPIO_ReadPin(TECLA_CONFIRMA_GPIO_Port, TECLA_CONFIRMA_Pin)){
									Estado = GRAVAR_DADO;
									HAL_Delay(100);
								}

								// Escreve cabeçalho
								lcd_posicao_do_cursor(0,0);
								lcd_escreve_string("Insira dado p/ FLASH\r");

								// Escreve o valor do dado que será armazenado
								lcd_posicao_do_cursor(2,0);
								sprintf(escreve_display,"Dado: 0x%04X\r", ValorEscrita);
								lcd_escreve_string(escreve_display);

								// Escreve endereço onde dado será armazenado
								lcd_posicao_do_cursor(3,0);
								sprintf(escreve_display,"End.: 0x%08X\r", END_INICIAL);
								lcd_escreve_string(escreve_display);
							}

							break;

			// Grava dado configurado no estado SOLICITAR_DADO e le novamente a posição de FLASH
			case GRAVAR_DADO:
							FLASH_apaga(END_INICIAL, 1);
							FLASH_escreve_16bits(END_INICIAL, &ValorEscrita);
							FLASH_le_16bits(END_INICIAL, &ValorLeitura);
							Estado = EXIBIR_DADO;
							break;

			// Exibe dado da FLASH
			case EXIBIR_DADO:
							// Escreve cabeçalho
							lcd_limpa_display();
							lcd_posicao_do_cursor(0,0);
							lcd_escreve_string("Dado na FLASH\r");

							// Escreve o valor Lido na FLASH
							lcd_posicao_do_cursor(2,0);
							sprintf(escreve_display,"Dado: 0x%04X\r", ValorLeitura);
							lcd_escreve_string(escreve_display);

							// Escreve endereço do dado lido
							lcd_posicao_do_cursor(3,0);
							sprintf(escreve_display,"End.: 0x%08X\r", END_INICIAL);
							lcd_escreve_string(escreve_display);
							Estado = MAIN_LOOP;
							break;
		}
	}

#endif


// Se END_INICIAL == 0xFFFFFFFF (livre, solicita dado (32 bits) para armazenar na FLASH
// Se END_INICIAL != 0xFFFFFFFF (ocupado, exibe valor (32 bits) e endereço armazenado na flash)
#if defined(TESTE_E)

	typedef enum{
		LER_DADO,
		SOLICITAR_DADO,
		GRAVAR_DADO,
		EXIBIR_DADO,
		MAIN_LOOP
	}TypedefEstado;

	TypedefEstado Estado = LER_DADO;
	uint32_t ValorLeitura = 0u;
	uint32_t ValorEscrita = 0u;
	int8_t   escreve_display[21] = {0};

	lcd_20x4_4bits_Init();

	while (Estado != MAIN_LOOP){

		switch (Estado){
			// Ao inicializar, verifica se endereço de memória está livre ou com informações gravadas
			case LER_DADO:
							FLASH_le_32bits(END_INICIAL, &ValorLeitura);
							if (ValorLeitura == 0xFFFFFFFF)
								Estado = SOLICITAR_DADO;
							else
								Estado = EXIBIR_DADO;
							break;
			// Usuário configura dado que deseja gravar na FLASH via display + teclado
			case SOLICITAR_DADO:
							while(Estado == SOLICITAR_DADO){
								if(!HAL_GPIO_ReadPin(TECLA_UP_GPIO_Port, TECLA_UP_Pin)){     // Tecla up (soma)
									ValorEscrita++;
									HAL_Delay(50);
								}

								if(!HAL_GPIO_ReadPin(TECLA_DOWN_GPIO_Port, TECLA_DOWN_Pin)){ // Tecla down (subtrai)
									ValorEscrita--;
									HAL_Delay(50);
								}
								if(!HAL_GPIO_ReadPin(TECLA_LEFT_GPIO_Port, TECLA_LEFT_Pin)){
									ValorEscrita += 0x10000;
									HAL_Delay(50);
								}
								if(!HAL_GPIO_ReadPin(TECLA_RIGHT_GPIO_Port, TECLA_RIGHT_Pin)){
									ValorEscrita -= 0x10000;
									HAL_Delay(50);
								}
								if(!HAL_GPIO_ReadPin(TECLA_CONFIRMA_GPIO_Port, TECLA_CONFIRMA_Pin)){
									Estado = GRAVAR_DADO;
									HAL_Delay(100);
								}

								// Escreve cabeçalho
								lcd_posicao_do_cursor(0,0);
								lcd_escreve_string("Insira dado p/ FLASH\r");

								// Escreve o valor do dado que será armazenado
								lcd_posicao_do_cursor(2,0);
								sprintf(escreve_display,"Dado: 0x%08X\r", ValorEscrita);
								lcd_escreve_string(escreve_display);

								// Escreve endereço onde dado será armazenado
								lcd_posicao_do_cursor(3,0);
								sprintf(escreve_display,"End.: 0x%08X\r", END_INICIAL);
								lcd_escreve_string(escreve_display);
							}

							break;

			// Grava dado configurado no estado SOLICITAR_DADO e le novamente a posição de FLASH
			case GRAVAR_DADO:
							FLASH_apaga(END_INICIAL, 1);
							FLASH_escreve_32bits(END_INICIAL, &ValorEscrita);
							FLASH_le_32bits(END_INICIAL, &ValorLeitura);
							Estado = EXIBIR_DADO;
							break;

			// Exibe dado da FLASH
			case EXIBIR_DADO:
							// Escreve cabeçalho
							lcd_limpa_display();
							lcd_posicao_do_cursor(0,0);
							lcd_escreve_string("Dado na FLASH\r");

							// Escreve o valor Lido na FLASH
							lcd_posicao_do_cursor(2,0);
							sprintf(escreve_display,"Dado: 0x%08X\r", ValorLeitura);
							lcd_escreve_string(escreve_display);

							// Escreve endereço do dado lido
							lcd_posicao_do_cursor(3,0);
							sprintf(escreve_display,"End.: 0x%08X\r", END_INICIAL);
							lcd_escreve_string(escreve_display);
							Estado = MAIN_LOOP;
							break;
		}
	}

#endif

// Se END_INICIAL == 0xFFFFFFFF (livre, solicita dado (string[8]) para armazenar na FLASH a partir de END_INICIAL
// Se END_INICIAL != 0xFFFFFFFF (ocupado, exibe dado (string[8]) a partir de END_INICIAL até end. de memória possuir 0xFFFFFFFF
#if defined(TESTE_F)

	typedef enum{
		LER_DADO,
		SOLICITAR_DADO,
		GRAVAR_DADO,
		EXIBIR_DADO,
		MAIN_LOOP
	}TypedefEstado;

	TypedefEstado Estado = LER_DADO;
	uint16_t ValorLeitura       = 0;
	int8_t StringLeitura[9]     = {0};
	int8_t StringEscrita[9]     = {0};
	int8_t escreve_display[21]  = {0};
	uint8_t index               =  0 ;

	memset(StringEscrita, 0x61, 8);

	lcd_20x4_4bits_Init();

	while (Estado != MAIN_LOOP){

		switch (Estado){
			// Ao inicializar, verifica se endereço de memória está livre ou com informações gravadas
			case LER_DADO:
							FLASH_le_16bits(END_INICIAL, &ValorLeitura);
							if (ValorLeitura == 0xFFFF)
								Estado = SOLICITAR_DADO;
							else
								Estado = EXIBIR_DADO;
							break;
			// Usuário configura dado que deseja gravar na FLASH via display + teclado
			case SOLICITAR_DADO:
							while(Estado == SOLICITAR_DADO){
								if(!HAL_GPIO_ReadPin(TECLA_UP_GPIO_Port, TECLA_UP_Pin)){     // Tecla up (soma)
									StringEscrita[index]++;
									HAL_Delay(50);
								}

								if(!HAL_GPIO_ReadPin(TECLA_DOWN_GPIO_Port, TECLA_DOWN_Pin)){ // Tecla down (subtrai)
									StringEscrita[index]--;
									HAL_Delay(50);
								}
								if((!HAL_GPIO_ReadPin(TECLA_LEFT_GPIO_Port, TECLA_LEFT_Pin)) && (index > 0)){
									index--;
									HAL_Delay(50);
								}
								if((!HAL_GPIO_ReadPin(TECLA_RIGHT_GPIO_Port, TECLA_RIGHT_Pin) && (index < 8)) ){
									index++;
									HAL_Delay(50);
								}
								if(!HAL_GPIO_ReadPin(TECLA_CONFIRMA_GPIO_Port, TECLA_CONFIRMA_Pin)){
									Estado = GRAVAR_DADO;
									HAL_Delay(100);
								}

								// Escreve cabeçalho
								lcd_posicao_do_cursor(0,0);
								lcd_escreve_string("Insira dado p/ FLASH\r");

								// Escreve o valor do dado que será armazenado
								lcd_posicao_do_cursor(2,0);
								sprintf(escreve_display,"Dado: %s\r", StringEscrita);
								lcd_escreve_string(escreve_display);

								// Escreve endereço onde dado será armazenado
								lcd_posicao_do_cursor(3,0);
								sprintf(escreve_display,"End.: 0x%08X\r", END_INICIAL);
								lcd_escreve_string(escreve_display);
							}

							break;

			// Grava dado configurado no estado SOLICITAR_DADO e le novamente a posição de FLASH
			case GRAVAR_DADO:
							FLASH_apaga(END_INICIAL, 1);
							FLASH_escreve_string(END_INICIAL, StringEscrita);
							Estado = EXIBIR_DADO;
							break;

			// Exibe dado da FLASH
			case EXIBIR_DADO:
							// Escreve cabeçalho
							lcd_limpa_display();
							lcd_posicao_do_cursor(0,0);
							lcd_escreve_string("Dado na FLASH\r");

							// Escreve o valor Lido na FLASH
							lcd_posicao_do_cursor(2,0);
							FLASH_le_string_0xFF(END_INICIAL, StringLeitura);
							sprintf(escreve_display,"Dado: %s\r", StringLeitura);
							lcd_escreve_string(escreve_display);

							// Escreve endereço do dado lido
							lcd_posicao_do_cursor(3,0);
							sprintf(escreve_display,"End.: 0x%08X\r", END_INICIAL);
							lcd_escreve_string(escreve_display);
							Estado = MAIN_LOOP;
							break;
		}
	}

#endif


// Teste utilizado na introdução do video
#if defined(TESTE_G)

    #define COM_FLASH // COM_FLASH = Armazena na FLASH / SEM_FLASH = Não armazena na FLASH

	uint16_t contagem = 0;
	uint16_t ValorLeitura = 0;
	int8_t escreve_display[21] = {0};
	lcd_20x4_4bits_Init();
	lcd_limpa_display();

	#if defined (COM_FLASH)
		FLASH_le_16bits(END_INICIAL, &ValorLeitura);
		if(ValorLeitura != 0xFFFF){
			contagem = ValorLeitura;
		}
	#endif

	while(1){
		if(!HAL_GPIO_ReadPin(TECLA_UP_GPIO_Port, TECLA_UP_Pin)){
			contagem++;
			#if defined (COM_FLASH)
				FLASH_apaga(END_INICIAL,1);
				FLASH_escreve_16bits(END_INICIAL, &contagem);
			#endif
		}
	}


#endif

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	HAL_Delay(1000);
  	#if defined(TESTE_A)
  	int8_t SetPoint = 1;
	#elif defined(TESTE_B)
  	int8_t SetPoint = 2;
	#elif defined(TESTE_C)
  	int8_t SetPoint = 3;
	#elif defined(TESTE_D)
	int8_t SetPoint = 4;
	#elif defined(TESTE_E)
	int8_t SetPoint = 5;
	#elif defined(TESTE_F)
	int8_t SetPoint = 6;
	#endif

	while (1)
	{
	  	HAL_Delay(1000);
		for (int8_t i = 0; i < SetPoint; i++){
	  			HAL_GPIO_TogglePin(LED_PLACA_GPIO_Port, LED_PLACA_Pin);
	  			HAL_Delay(120);
	  			HAL_GPIO_TogglePin(LED_PLACA_GPIO_Port, LED_PLACA_Pin);
	  			HAL_Delay(120);
	  		}




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

  /** Initializes the CPU, AHB and APB busses clocks 
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
  /** Initializes the CPU, AHB and APB busses clocks 
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
  HAL_GPIO_WritePin(LED_PLACA_GPIO_Port, LED_PLACA_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LCD_D4_Pin|LCD_D5_Pin|LED_VERMELHO_Pin|LCD_D6_Pin 
                          |LCD_D7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LCD_RS_Pin|LCD_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_PLACA_Pin */
  GPIO_InitStruct.Pin = LED_PLACA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_PLACA_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_D4_Pin LCD_D5_Pin LED_VERMELHO_Pin LCD_D6_Pin 
                           LCD_D7_Pin */
  GPIO_InitStruct.Pin = LCD_D4_Pin|LCD_D5_Pin|LED_VERMELHO_Pin|LCD_D6_Pin 
                          |LCD_D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_RS_Pin LCD_EN_Pin */
  GPIO_InitStruct.Pin = LCD_RS_Pin|LCD_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : TECLA_UP_Pin TECLA_LEFT_Pin TECLA_RIGHT_Pin TECLA_DOWN_Pin 
                           TECLA_CANCELA_Pin TECLA_CONFIRMA_Pin */
  GPIO_InitStruct.Pin = TECLA_UP_Pin|TECLA_LEFT_Pin|TECLA_RIGHT_Pin|TECLA_DOWN_Pin 
                          |TECLA_CANCELA_Pin|TECLA_CONFIRMA_Pin;
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
