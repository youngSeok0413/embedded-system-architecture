#pragma once



#include "register.h"

bool isLedSet[][] = {};

void ledInit(uint8_t port, uint8_t pin);
void ledOn(uint8_t port, uint8_t pin);
void ledOff(uint8_t port, uint8_t pin);
void ledToggle(uint8_t port, uint8_t pin);