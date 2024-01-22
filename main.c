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
	tim2_init(72000000, 1024 , 1);
	gpioInit();
	bttnInterrupt(13);

	extern bool pressed;

	while(1)
	{
		gpioToggle(5);
		usDelay(100000);
		gpioToggle(5);
		msDelay(100);
	}

	return 0;
}

