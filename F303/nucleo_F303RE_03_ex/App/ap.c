/*
 * ap.c
 *
 *  Created on: 2026. 5. 22.
 *      Author: ljy
 */


#include "ap.h"

#include "usart.h"


uint32_t cnt = 0;

void apInit(void)
{
	ledInit();
}

void apMain(void)
{
  uint32_t pre_time;
//  uint32_t pre_time2;

  pre_time = millis();
//  pre_time2 = millis();

  uint8_t buffer[256];

  sprintf((char *)buffer, "Firmware Start\r\n");
  HAL_UART_Transmit(&huart2, buffer, strlen((char *)buffer), 100);

  HAL_StatusTypeDef serial_status; // uart 상태 저장

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

	    //uartWrite(_DEF_CH1,(uint8_t *) "test\n", 5);
	    uartPrintf(_DEF_CH1, "test %d\n", millis());
	  }

//	  if(millis() - pre_time2 >= 1000)
//    {
//      pre_time2 = millis();
//
//
//
//      sprintf((char *)buffer, "TX test cnt : %d\r\n", cnt++);
//      HAL_UART_Transmit(&huart2, buffer, strlen((char *)buffer), 100);
//    }
	  serial_status = HAL_UART_Receive(&huart2, buffer, 1, 100);
	  if(serial_status == HAL_OK)
	  {
	    HAL_UART_Transmit(&huart2, buffer, 1, 100);
	  }

	  //delay(500);

	}

}
