#pragma once

#include "register.h"

#define DMB()           volatile __asm__("dmb");

void timer_init();