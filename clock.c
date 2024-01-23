/*
 * clock.c
 *
 *  Created on: Jan 15, 2024
 *      Author: shipg
 */

#include "clock.h"

#include "interrupt.h"

/*
 * By default 8 MHz internal clock is used (HSI)
 * Set up as 72 MHz (HSE-PLL)
 *
 * 25M ->   /5    ->   *8    ->   /5    ->   *9   -> 72 MHz
 * HSE -> PreDiv2 -> Pll2Mul -> PreDiv1 -> PllMul -> System Clock
 * Set Prediv1Src = PLL2, Set PllSrc as Prediv1
 *
 * 25 MHz External clock is selected as the source clock (HSE)
 * It is divided by 5 with PreDiv2, then muliplied by 8 with Pll2Mul
 * Then it is divided by 5 with PreDiv1, then multiplied by 9 with PllMul
 * Then choose Pll as the clock source
 */
void rcc_init(void)
{
	uint32_t reg32;

	// HSI ON(default)
	RCC->CR |= (uint32_t)0x00000001;
	DMB();
	while (!(RCC->CR & (1 << 1)))
		;

	reg32 = RCC->CFGR;
	reg32 &= ~((0b1 << 0) | (0b1 << 1));
	RCC->CFGR = reg32 | (0b00 << 0);
	DMB();
	while ((RCC->CFGR & (0b11 << 2)) != 0b0000)
		;

	// FLASH set
	FLASH->ACR = 0x12;
	DMB();

	// HSE ON
	RCC->CR |= (0b1 << 16);
	DMB();
	while (!(RCC->CR & (0b1 << 17)))
		;

	// AHB, APB, APB2, ADC, PLL entry, HSE divider, PLL Mul
	// AHB
	reg32 = RCC->CFGR;
	reg32 &= ~(0b1111 << 4);
	RCC->CFGR = reg32 | (0b0000 << 4);
	DMB();

	// APB1
	reg32 = RCC->CFGR;
	reg32 &= ~(0b111 << 8);
	RCC->CFGR = reg32 | (0b100 << 8);
	DMB();

	// APB2
	reg32 = RCC->CFGR;
	reg32 &= ~(0b111 << 11);
	RCC->CFGR = reg32 | (0b000 << 11);
	DMB();

	// ADC
	reg32 = RCC->CFGR;
	reg32 &= ~(0b11 << 14);
	RCC->CFGR = reg32 | (0b00 << 14);
	DMB();

	// PLLSRC
	reg32 = RCC->CFGR;
	reg32 &= ~(0b1 << 16);
	RCC->CFGR = reg32 | (0b1 << 16);
	DMB();

	// PLL entry
	reg32 = RCC->CFGR;
	reg32 &= ~(0b1 << 17);
	RCC->CFGR = reg32 | (0b0 << 17);
	DMB();

	// PLL mul
	reg32 = RCC->CFGR;
	reg32 &= ~(0b1111 << 18);
	RCC->CFGR = reg32 | (0b0111 << 18);
	DMB();

	// PLL sysclk source on
	RCC->CR |= (1 << 24);
	DMB();
	while ((RCC->CR & (1 << 25)) == 0)
		;

	// select pll
	reg32 = RCC->CFGR;
	reg32 &= ~((1 << 1) | (1 << 0));
	RCC->CFGR = reg32 | (0b10 << 0);
	DMB();

	while ((RCC->CFGR & (0b11 << 2)) != (0b10 << 2))
		;
	// HSI off
	// RCC->CR &= ~(1 << 0);
}

void systick_init(void)
{
	STK->CTRL |= 1 << 1;
	STK->CTRL |= 1 << 2; // CLKSRC selection(default : 0)

	STK->LOAD = 71999; // ms
	STK->VAL = 0;

	STK->CTRL |= 1 << 0;
}

void tim2_init(void)
{
	RCC->APB1RSTR |= 1 << 0;
	DMB();
	RCC->APB1RSTR &= ~((uint32_t)1);
	RCC->APB1ENR |= 1 << 0;

	TIM2->CR1 &= ~(0x3FF);
	DMB();
	//set timer scaler
	TIM2->PSC = 9-1;
	TIM2->ARR = 8-1;
	TIM2->CNT = 0;
	TIM2->SR &= ~(0x3FF);

	//clock enable
	TIM2->CR1 |= 1 << 0;
	TIM2->DIER |= 1 << 0;
	DMB();

	nvic_irq_priority(28, 1);
	nvic_irq_enable(28);

	return;
}

uint32_t SysTick(void)
{
	extern uint32_t SYS_TIM;
	return SYS_TIM;
}

void msDelay(uint32_t ms)
{
	extern uint32_t TIMER;
	TIMER = ms;
	while (TIMER > 0)
		;
}

void usDelay(uint32_t us)
{
	extern uint32_t TIM2_TIMER;
	TIM2_TIMER = us;
	while (TIM2_TIMER > 0)
		;
}
