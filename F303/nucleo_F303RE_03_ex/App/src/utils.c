/*
 * utils.c
 *
 *  Created on: 2026. 5. 22.
 *      Author: ljy
 */


#include "utils.h"

void delay(uint32_t ms)
{
  HAL_Delay(ms);
}

uint32_t millis(void)
{
  return HAL_GetTick();
}
