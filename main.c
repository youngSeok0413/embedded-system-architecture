/*
 * main.c
 *
 *  Created on: Jan 15, 2024
 *      Author: shipg
 */

//included library
#include "clock.h"
#include "led.h"
#include "gpio.h"
#include "interrupt.h"

int main()
{
	rcc_init();
	systick_init();
	gpioInit();
	bttnInterrupt(13);

	extern bool pressed;

	while(1)
	{
		if(pressed) gpioToggle(5);
		msDelay(10);
	}

	return 0;
}

