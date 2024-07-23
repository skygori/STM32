/*
 * led.h
 *
 *  Created on: May 17, 2023
 *      Author: ljy
 */

#ifndef INCLUDE_LED_H_
#define INCLUDE_LED_H_

#include "def.h"

bool ledInit(void);
void lenOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);

#endif /* INCLUDE_LED_H_ */
