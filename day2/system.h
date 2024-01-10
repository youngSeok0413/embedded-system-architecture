#pragma once

#include "register.h"



//nvic enable
void nvic_enable(uint8_t n);

//nvic disable
void nvic_disable(uint8_t n);

//nvic set priority
void nvic_setPriority(uint8_t n, uint8_t priority);

//flash set waitstate
void flash_set_waitstates(void);