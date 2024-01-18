/*
 * clock.h
 *
 *  Created on: Jan 15, 2024
 *      Author: shipg
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "register.h"

#define DMB() __asm__ volatile ("dmb");
#define WFI() __asm__ volatile ("wfi");

void rcc_init(void);
void systick_init(void);
uint32_t SysTick(void);
void msDelay(uint32_t ms);

#endif /* CLOCK_H_ */
