/*
 * gpio.c
 *
 *  Created on: Jan 17, 2024
 *      Author: shipg
 */
#include "gpio.h"

//gpio : (a, 5 / c, 13)

void gpioInit()
{
	uint32_t reg32;

	RCC->APB2ENR |= (1 << 2); //A, C
	RCC->APB2ENR |= (1 << 4);

	//port a, 5 : output mode(50MHz, push-pull)
	reg32 = GPIOA->CRL;
	reg32 &= ~((uint32_t) 0b1111 << 20);
	GPIOA->CRL = reg32 | (0b11 << 20) | (0b00 << 22);

	//port c, 13 : input mode(pull-up/pull-down)
	reg32 = GPIOC->CRH;
	reg32 &= ~((uint32_t) 0b1111 << 20);
	GPIOC->CRH = reg32 | (0b00 << 20) | (0b10 << 22);
}

void gpioOn(uint8_t pin)
{
	GPIOA->BSRR |= (1 << pin);
}

void gpioOff(uint8_t pin)
{
	GPIOA->BSRR |= (1 << (pin + 16));
}

void gpioToggle(uint8_t pin)
{
	if ((GPIOA->ODR & (1 << pin)) == (1 << pin))
		gpioOff(pin);
	else
		gpioOn(pin);
}

bool gpioInput(uint8_t pin)
{
	return (GPIOC->IDR & (1 << pin));
}
