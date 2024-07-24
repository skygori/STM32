/*
 * ap.c
 *
 *  Created on: May 17, 2023
 *      Author: ljy
 */

#include "stm32g4xx.h"

#include "ap.h"

static void infoCli(uint8_t argc, const char **argv);

void apInit(void)
{
	cliInit(); 	// first init
	uartInit();

	cliAdd("info", infoCli);
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
			//uartPrintf(_DEF_CH1, "test %f\n", 5);
		}

		cliMain();
	}

}

void infoCli(uint8_t argc, const char **argv)
{
	bool ret = false;

	if(argc == 1 && cliIsStr(argv[0], "test"))
	{
		cliPrintf("infoCli run test\n");
		ret = true;
	}

	if(argc == 2 && cliIsStr(argv[0], "print"))
	{
		uint8_t count;

		count = (uint8_t)cliGetData(argv[1]);
		for(int i = 0; i < count; i++)
		{
			cliPrintf("print %d/%d\n", i+1, count);
		}
		ret = true;
	}

	if(argc == 1 && cliIsStr(argv[0], "button"))
	{
		while(cliKeepLoop())
		{
			cliPrintf("\n");
		}
	}

	if(ret == false)
	{
		cliPrintf("info test\n");
		cliPrintf("info print 0~10\n");
		cliPrintf("info button\n");
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

