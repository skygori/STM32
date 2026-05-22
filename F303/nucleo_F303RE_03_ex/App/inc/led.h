/*
 * led.h
 *
 *  Created on: 2026. 5. 22.
 *      Author: ljy
 */

#ifndef INC_LED_H_
#define INC_LED_H_


#include "def.h"

#ifdef _USE_HW_LED

#define LED_CH_MAX    HW_LED_CH_MAX

bool ledInit(void);
void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);

#endif

#endif /* INC_LED_H_ */
