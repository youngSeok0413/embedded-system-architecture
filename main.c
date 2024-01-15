/*
 * main.c
 *
 *  Created on: Jan 15, 2024
 *      Author: shipg
 */

#include "clock.h"
#include "led.h"

int main()
{
	rcc_init();
	systick_init();
	ledInit();

	while(1)
	{
		ledToggle('A', 5);
		msDelay(100);
	}

	return 0;
}

