/*
 * RS485.c
 *
 *  Created on: May 22, 2023
 *      Author: ljy
 */


#include "uart.h"

#define UART_Q_BUF_MAX 256

extern UART_HandleTypeDef huart1;
//extern UART_HandleTypeDef hlpuart1;

static uint16_t q_in = 0; // static 이 파일 에서만 사용 하도록
static uint16_t q_out = 0;
static uint8_t q_buf[UART_Q_BUF_MAX];
//static uint8_t q_data; // 한 바이트만 받도록




bool uartInit(void)
{
	HAL_UART_Receive_DMA(&huart1, &q_buf[0], UART_Q_BUF_MAX);
	//HAL_UART_Receive_DMA(&hlpuart1, &q_buf[0], UART_Q_BUF_MAX);
	return true;
}

uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length)
{
	uint32_t ret = 0;
	HAL_StatusTypeDef hal_ret;

	switch(ch)
	{
		case _DEF_CH1:
			hal_ret = HAL_UART_Transmit(&huart1, p_data, length, 100);
			if(hal_ret == HAL_OK)
			{
				ret = length;
			}
			break;
		case _DEF_CH2:
			/*hal_ret = HAL_UART_Transmit(&hlpuart1, p_data, length, 100);
			if(hal_ret == HAL_OK)
			{
				ret = length;
			}*/
			break;
	}

	return ret;
}

uint32_t uartAvailable(uint8_t ch)
{
	uint32_t ret = 0;

	switch(ch)
	{
	case _DEF_CH1:
		q_in = (UART_Q_BUF_MAX - huart1.hdmarx->Instance->CNDTR) % UART_Q_BUF_MAX;
		ret = (UART_Q_BUF_MAX + q_in - q_out) % UART_Q_BUF_MAX;
		break;
	case _DEF_CH2:
		//q_in = (UART_Q_BUF_MAX - hlpuart1.hdmarx->Instance->CNDTR) % UART_Q_BUF_MAX;
		//ret = (UART_Q_BUF_MAX + q_in - q_out) % UART_Q_BUF_MAX;
		break;
	}

	return ret;
}

uint8_t uartRead(uint8_t ch)
{
	uint8_t ret = 0;

	switch(ch)
	{
	case _DEF_CH1:
		if(q_out != q_in)
		{
			ret = q_buf[q_out];
			q_out = (q_out + 1) % UART_Q_BUF_MAX;
		}
		break;
	case _DEF_CH2:
		if(q_out != q_in)
		{
			ret = q_buf[q_out];
			q_out = (q_out + 1) % UART_Q_BUF_MAX;
		}
		break;
	}

	return ret;
}

uint32_t uartPrintf(uint8_t ch, const char *fmt, ...)
{
	uint32_t ret = 0;
	va_list arg;
	char print_buf[256];

	va_start(arg, fmt);

	int len;
	len = vsnprintf(print_buf, 256, fmt, arg);

	va_end(arg);

	if(len > 0)
	{
		ret = uartWrite(ch, (uint8_t *)print_buf, len);
	}

	return ret;
}

uint32_t uartVPrintf(uint8_t ch, const char *fmt, va_list arg)
{
	uint32_t ret = 0;
	char print_buf[256];

	int len;
	len = vsnprintf(print_buf, 256, fmt, arg);


	if(len > 0)
	{
		ret = uartWrite(ch, (uint8_t *)print_buf, len);
	}

	return ret;
}
