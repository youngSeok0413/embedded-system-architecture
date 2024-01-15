/*
 * led.h
 *
 *  Created on: Jan 15, 2024
 *      Author: shipg
 */

#ifndef LED_H_
#define LED_H_

#include "register.h"

void ledInit(void);
void ledOn(uint8_t port, uint8_t pin);
void ledOff(uint8_t port, uint8_t pin);
void ledToggle(uint8_t port, uint8_t pin);

#endif /* LED_H_ */
