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
void tim2_init(void);
uint32_t SysTick(void);
void msDelay(uint32_t ms);
void usDelay(uint32_t us);

#endif /* CLOCK_H_ */
