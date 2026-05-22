/*
 * ap.c
 *
 *  Created on: 2026. 5. 22.
 *      Author: ljy
 */


#include "ap.h"

void apInit(void)
{
	;
}
void apMain(void)
{
	while(1)
	{
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	  HAL_Delay(500);
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	  HAL_Delay(500);
	}

}
