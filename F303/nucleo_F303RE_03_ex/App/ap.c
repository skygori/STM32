/*
 * ap.c
 *
 *  Created on: 2026. 5. 22.
 *      Author: ljy
 */


#include "ap.h"

void apInit(void)
{
	ledInit();
}

void apMain(void)
{
  uint32_t pre_time;

  pre_time = millis();

	while(1)
	{
//	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
//	  HAL_Delay(500);
//	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
//	  HAL_Delay(500);
	  if(millis() - pre_time >= 500)
	  {
	    pre_time = millis();

	    ledToggle(RUN_LED);
	  }

	  //delay(500);

	}

}
