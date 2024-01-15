/*
 * clock.c
 *
 *  Created on: Jan 15, 2024
 *      Author: shipg
 */

#include "clock.h"

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

	//HSI ON(default)
	RCC->CR |= (uint32_t) 0x00000001;
	DMB();
	while (!(RCC->CR & (1 << 1)))
		;

	reg32 = RCC->CFGR;
	reg32 &= ~((0b1 << 0) | (0b1 << 1));
	RCC->CFGR = reg32 | (0b00 << 0);
	DMB();
	while ((RCC->CFGR & (0b11 << 2)) != 0b0000)
		;

	//FLASH set
	FLASH->ACR = 0x12;
	DMB();

	//HSE ON
	RCC->CR |= (0b1 << 16);
	DMB();
	while (!(RCC->CR & (0b1 << 17)))
		;

	//AHB, APB, APB2, ADC, PLL entry, HSE divider, PLL Mul
	//AHB
	reg32 = RCC->CFGR;
	reg32 &= ~(0b1111 << 4);
	RCC->CFGR = reg32 | (0b0000 << 4);
	DMB();

	//APB1
	reg32 = RCC->CFGR;
	reg32 &= ~(0b111 << 8);
	RCC->CFGR = reg32 | (0b100 << 8);
	DMB();

	//APB2
	reg32 = RCC->CFGR;
	reg32 &= ~(0b111 << 11);
	RCC->CFGR = reg32 | (0b000 << 11);
	DMB();

	//ADC
	reg32 = RCC->CFGR;
	reg32 &= ~(0b11 << 14);
	RCC->CFGR = reg32 | (0b00 << 14);
	DMB();

	//PLLSRC
	reg32 = RCC->CFGR;
	reg32 &= ~(0b1 << 16);
	RCC->CFGR = reg32 | (0b1 << 16);
	DMB();

	//PLL entry
	reg32 = RCC->CFGR;
	reg32 &= ~(0b1 << 17);
	RCC->CFGR = reg32 | (0b0 << 17);
	DMB();

	//PLL mul
	reg32 = RCC->CFGR;
	reg32 &= ~(0b1111 << 18);
	RCC->CFGR = reg32 | (0b1111 << 18);
	DMB();

	//PLL sysclk source on
	RCC->CR |= (1 << 24);
	DMB();
	while ((RCC->CR & (1 << 25)) == 0);

	//select pll
	reg32 = RCC->CFGR;
	reg32 &= ~((1 << 1) | (1 << 0));
	RCC->CFGR = reg32 | (0b10 << 0);
	DMB();

	while ((RCC->CFGR & (0b11 << 2)) != (0b10 << 2));

	//HSI off
	//RCC->CR &= ~(1 << 0);
}

void systick_init(void)
{
	STK->CTRL |= 1 << 1;
	STK->LOAD = 72999;	//clk_src = 72000000Hz (what we want => make systick interrupt every 1ms)
	STK->VAL = 0;

	STK->CTRL |= 1 << 0;
}

void msDelay(uint32_t ms)
{
	extern uint32_t STK_TIME;
	STK_TIME = ms;
	while (STK_TIME > 0);
}
