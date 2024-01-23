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
	tim2_init();
	gpioInit();
	bttnInterrupt(13);

	while(1)
	{
		gpioToggle(5);
		usDelay(100000);
	}

	return 0;
}

