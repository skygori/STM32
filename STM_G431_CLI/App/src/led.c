/*
 * led.c
 *
 *  Created on: May 17, 2023
 *      Author: ljy
 */

#include "led.h"

bool ledInit(void)
{
	return true;
}

void lenOn(uint8_t ch)
{
	switch(ch)
	{
		case _DEF_CH1:
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
			break;
	}
}

void ledOff(uint8_t ch)
{
	switch(ch)
	{
		case _DEF_CH1:
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
			break;
	}
}

void ledToggle(uint8_t ch)
{
	switch(ch)
	{
		case _DEF_CH1:
			HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			break;
	}
}
