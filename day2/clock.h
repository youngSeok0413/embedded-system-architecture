#pragma once

#include "register.h"
#include "system.h"
#include "interrupt.h"


void rcc_init(void);
void systick_init(uint32_t ticks);
void usDelay(uint32_t us);
void msDelay(uint32_t ms);