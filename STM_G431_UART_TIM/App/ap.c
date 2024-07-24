/*
 * ap.c
 *
 *  Created on: May 17, 2023
 *      Author: ljy
 */

#include "stm32g4xx.h"

#include "ap.h"

void apInit(void)
{
	uartInit();
}

void apMain(void)
{
	uint32_t pre_time;

	pre_time = millis();

	while(1)
	{
		if(millis() - pre_time >= 1000)
		{
			pre_time = millis();
			ledToggle(_DEF_CH1);
			uartPrintf(_DEF_CH1, "test %f\n", 5);
		}
	}

}
/*
void apMain(void)
{
	while(1)
	{
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		HAL_Delay(500);
	}

}
*/
/*
void apMain(void)
{
	uint32_t pre_time;

	while(1)
	{
		if(HAL_GetTick() - pre_time >= 500)
		{
			pre_time = HAL_GetTick();
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}
	}
}
*/

