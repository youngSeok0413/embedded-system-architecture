/*
 * interrupt.h
 *
 *  Created on: Jan 17, 2024
 *      Author: shipg
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "register.h"

void nvic_irq_enable(uint8_t pos);
void nvic_irq_disable(uint8_t pos);
void nvic_irq_priority(uint8_t pos, uint8_t priority);

void bttnInterrupt(uint8_t pin);

#endif /* INTERRUPT_H_ */
