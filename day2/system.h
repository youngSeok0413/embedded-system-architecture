#pragma once

#include "register.h"



//nvic enable
void nvic_enable(uint32_t n);

//nvic disable
void nvic_disable(uint32_t n);

//flash set waitstate
void flash_set_waitstates(void);