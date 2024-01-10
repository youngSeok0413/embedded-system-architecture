#pragma once

#include <stdint.h>

#include "register.h"

/**
 * default function(weak)
*/

/**
 * nvic interrupt function
*/
void isr_reset(void);
void isr_nmi(void);
void isr_hrdfault(void);
void isr_memmn(void);
void isr_busfault(void);
void isr_usgfault(void);

/**
 * reserved area : 0, 0, 0, 0
*/

void isr_svcall(void);
void isr_debug_monitor(void);

/**
 * reserved area : 0,
*/

void isr_pendsv(void);
void isr_systick(void);
void isr_wwdg(void);
void isr_pvd(void);
void isr_tamper(void);
void isr_rtc(void);
void isr_flash(void);
void isr_rcc(void);

void isr_exti0(void);
void isr_exti1(void);
void isr_exti2(void);
void isr_exti3(void);
void isr_exti4(void);

void isr_dma1_ch1(void);
void isr_dma1_ch2(void);
void isr_dma1_ch3(void); 
void isr_dma1_ch4(void);
void isr_dma1_ch5(void);
void isr_dma1_ch6(void);
void isr_dma1_ch7(void);

void isr_adc1_2(void);

void isr_can1_tx(void);
void isr_can1_rx0(void);
void isr_can1_rx1(void);
void isr_can1_sce(void);

void isr_exti9_5(void);

void isr_tim1_brk(void);
void isr_tim1_upd(void);
void isr_tim1_trg_com(void);
void isr_tim1_cc(void);
void isr_tim2(void);
void isr_tim3(void);
void isr_tim4(void);

void isr_i2c1_ev(void);
void isr_i2c1_err(void);
void isr_i2c2_ev(void);
void isr_i2c2_err(void);

void isr_spi1(void);
void isr_spi2(void);

void isr_usart1(void);
void isr_usart2(void);
void isr_usart3(void);

void isr_exti5_10(void);
void isr_rtc_alarm(void);
void isr_usb_otgfs_wkup(void);

/**
 * reserved : 0 0 0 0 0 0 0
*/