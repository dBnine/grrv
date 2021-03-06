/*----------------------------------------------------------------------------*/
/**
 * \file 		main.c
 * \brief 		Main program for PWM Project, test and validation of the PMW module
 * \authors 		Cgroup & ENSI Corp
 * \version 		0.1
 * \date 		25 septembre 2015
 * \copyright 		C group : Secuity Department
 * \bug 		no bug
 *
 */
/*----------------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "pwm.h"

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/**
   * \brief Main function PWM PROJECT
   * \param None
   * \retval 0   
   */
int main(void){

  int i = 0;
  int pls = 0;

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_PWM_PROP_Init();
  MX_PWM_STEER_CAM_Init();
  MX_PWM_LED_Init();

  /* Infinite loop */
  while (1)
  {
	switch(i){
		case (0) : pls = DUTY_CYCLE_0		; break;
		case (1) : pls = DUTY_CYCLE_25		; break;
		case (2) : pls = DUTY_CYCLE_50		; break;
		case (3) : pls = DUTY_CYCLE_75		; break;
		case (4) : pls = DUTY_CYCLE_100		; break;
	}
	pls=DUTY_CYCLE_75;
	HAL_Delay(2000);
	PWM_CH1_Pulse(pls);
	PWM_CH2_Pulse(pls);
	PWM_CH3_Pulse(pls);
	PWM_CH4_Pulse(pls);
	PWM_LED_Pulse(pls);
		
	if (i <=4)
		i++;
	if(i==5)
		i = 0;
  }
}

/**
   * \brief Configure the System Clock
   * \param None
   * \retval None   
   */
void SystemClock_Config(void){
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  __PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
}

/**
   * \brief Initialize all configured peripherals
   * \param None
   * \retval None
   */
void MX_GPIO_Init(void)
{
  /* GPIO Ports Clock Enable */
  __GPIOB_CLK_ENABLE();
  __GPIOC_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}
#endif


/************************  C group & ENSI Corp*********************************/
