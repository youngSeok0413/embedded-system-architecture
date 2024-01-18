/*
 * interrupt.c
 *
 *  Created on: Jan 17, 2024
 *      Author: shipg
 */


#include "interrupt.h"

void nvic_irq_enable(uint8_t pos)
{
	int i = pos/32;

	if (i == 0)
		NVIC->ISER0 |= (1 << (pos%32));
	else if (i == 1)
		NVIC->ISER1 |= (1 << (pos%32));
	else if (i == 2)
		NVIC->ISER2 |= (1 << (pos%32));
}

void nvic_irq_disable(uint8_t pos)
{
	int i = pos / 32;

	if (i == 0)
		NVIC->ICER0 |= (1 << (pos % 32));
	else if (i == 1)
		NVIC->ICER1 |= (1 << (pos % 32));
	else if (i == 2)
		NVIC->ICER2 |= (1 << (pos % 32));
}

void nvic_irq_priority(uint8_t pos, uint8_t priority)
{
	volatile uint8_t* ipri = ((volatile uint8_t*)(NVIC_IPR_BASE + pos));
	*ipri = priority;
}

void bttnInterrupt(uint8_t pin)
{
	uint32_t reg32;

	//afio clock enable
	RCC->APB2ENR |= (1 << 0); //AFIO enable
	RCC->APB2ENR |= (1 << 4); // port c

	reg32 = GPIOC->CRH;
	reg32 &= ~((uint32_t) 0b1111 << 20);

	//exti interrupt enable
	AFIO->EXTICR4 &= ~(0b1111 << 4);
	AFIO->EXTICR4 |= (0b0010 << 4);

	EXTI->IMR |= (1 << pin);
	EXTI->EMR |= (1 << pin);

	EXTI->RTSR |= (1 << pin);
	EXTI->FTSR &= ~((uint32_t) 1 << pin);

	nvic_irq_priority(40, 1);
	nvic_irq_enable(40);
}
