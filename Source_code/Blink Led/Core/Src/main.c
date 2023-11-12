/**
  Codigo de practica para hacer las luces de una patrulla
*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>
#include<stdio.h>
#include<stm32f407xx.h>
#include<stm32f4xx_hal.h>

static void MX_GPIO13_Init(void);
static void MX_GPIO15_Init(void);

int main(void)
{
	HAL_Init(); // Inicializa la biblioteca HAL
	MX_GPIO15_Init();
	MX_GPIO13_Init();
	while(1){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);


	}

}

static void MX_GPIO15_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  // Inicializa el sistema de periféricos GPIO
  __HAL_RCC_GPIOD_CLK_ENABLE();

  // Configura el pin GPIO PD15
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Modo push-pull para salida
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // Puedes ajustar la velocidad según sea necesario
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

// Init Gpio13
static void MX_GPIO13_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  // Inicializa el sistema de periféricos GPIO
  __HAL_RCC_GPIOD_CLK_ENABLE();

  // Configura el pin GPIO PD13
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Modo push-pull para salida
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // Puedes ajustar la velocidad según sea necesario
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}
