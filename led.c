/*
 * led.c
 *
 *  Created on: Jan 15, 2024
 *      Author: shipg
 */

#include "led.h"

void ledInit(void)
{
	//clock source
	uint32_t reg32;
	RCC->APB2ENR |= (1 << 2);

	reg32 = GPIOA->CRL;
	reg32 &= ~((uint32_t)0b1111 << 20);
	GPIOA->CRL = reg32 | (0b10 << 20) | (0b00 << 22);
}

void ledOn(uint8_t port, uint8_t pin)
{
	//GPIOA->ODR |= (1 << pin);
	GPIOA->BSRR |= (1 << pin);
}

void ledOff(uint8_t port, uint8_t pin)
{
	//GPIOA->ODR &= ~(1 << pin);
	GPIOA->BSRR |= (1 << (pin + 16));
}

void ledToggle(uint8_t port, uint8_t pin)
{
	if((GPIOA->ODR & (1 << pin)) == (1 << pin))
		ledOff(port, pin);
	else
		ledOn(port, pin);
}
