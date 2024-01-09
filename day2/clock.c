#include "clock.h"

void rcc_config(void);

void rcc_config(void)
{
    uint32_t reg32;

    //HSI ON(temp)
    RCC_CR |= ((uint32_t)1 << 0);
    DMB();

    while((RCC_CR & ((uint32_t)1 << 1)) == 0);

    reg32 = RCC_CFGR;
    reg32 &= ~((uint32_t)(1 << 1) | (1 << 0));
    RCC_CFGR = (reg32 | (0x00 << 2));
    DMB();

    //HSE ON
    RCC_CR |= ((uint32_t)1 << 16);
    DMB();

    while ((RCC_CR & ((uint32_t)1 << 17)) == 0);

    reg32 = RCC_CFGR;
    reg32 &= ~((uint32_t)0xF0); 
    RCC_CFGR = (reg32 | (0x00 << 4)); //divide none
    DMB();

    reg32 = RCC_CFGR;
    reg32 &= ~((uint32_t)0x7 << 8);
    RCC_CFGR = (reg32 | ((uint32_t)0x04 << 8));
    DMB();

    reg32 = RCC_CFGR;
    reg32 &= ~((uint32_t)0x7 << 11);
    RCC_CFGR = (reg32 | ((uint32_t)0x00 << 8));
    DMB();

    //pll setting
    reg32 = RCC_CFGR;
    reg32 &= ~((uint32_t));
}