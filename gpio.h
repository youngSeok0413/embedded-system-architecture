/*
 * gpio.h
 *
 *  Created on: Jan 17, 2024
 *      Author: shipg
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "register.h"

void gpioInit();
void gpioOn(uint8_t ch);
void gpioOff(uint8_t ch);
void gpioToggle(uint8_t ch);
bool gpioInput(uint8_t ch);

#endif /* GPIO_H_ */
