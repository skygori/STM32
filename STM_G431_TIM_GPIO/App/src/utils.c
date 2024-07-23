/*
 * utils.c
 *
 *  Created on: May 17, 2023
 *      Author: ljy
 */

#include "utils.h"

void delay(uint32_t time_ms)
{
	HAL_Delay(time_ms);
}

uint32_t millis(void)
{
	return HAL_GetTick();
}
