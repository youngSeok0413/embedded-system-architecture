#include "clock.h"



#include "system.h"
#include "interrupt.h"



void rcc_init(void)
{
    uint32_t reg32;
    
    // hsi on + sysclk
    RCC_CR |= ((uint32_t)0x0001 << HSION);
    DMB();
    while (!(RCC_CR & (0x0001 << HSION))){};

    reg32 = RCC_CFGR;
    reg32 &= ~((1 << 1) | (1 << 0));
    RCC_CFGR = (reg32 | ((uint32_t)0x0000 << SW));
    DMB();

    // enabling hse
    RCC_CR |= ((uint32_t)0x0001 << HSEON);
    DMB();
    while (!(RCC_CR & (1 << HSERDY)));

    // flash prefetch buffer enable -> 72MHz
    FLASH_ACR |= ((uint32_t)0x0001 << PRFTBE);
    FLASH_ACR &= ~((uint32_t)0x0003 << LATENCY);
    FLASH_ACR |= ((uint32_t)0x0002 << LATENCY);

    // reset PLLSRC, PLLXTPRE, PLLMUL, ADC
    RCC_CFGR &= ~(((uint32_t)0x0001 << PLLSRC) |
                  ((uint32_t)0x0001 << PLLXTPRE) |
                  ((uint32_t)0x000F << PLLMUL));

    RCC_CFGR &= ~((uint32_t)0x0001 << PLLXTPRE);
    RCC_CFGR |= ((uint32_t)0x0001 << PLLSRC);
    RCC_CFGR |= ((uint32_t)0x0007 << PLLMUL);
    RCC_CFGR &= ~((uint32_t)0x000F << HPRE);
    RCC_CFGR |= ((uint32_t)0x0004 << PPRE1);
    RCC_CFGR |= ~((uint32_t)0x0007 << PPRE2);

    RCC_CR |= ((uint32_t)1 << PLLON);
    DMB();
    while (!(RCC_CR & (1 << PLLRDY)))
        ;

    RCC_CFGR &= ~((uint32_t)0x0003 << SW);
    RCC_CFGR |= ((uint32_t)0x0002 << SW);
    while ((RCC_CR & (0x0003 << SWS)) != ((uint32_t)0x0002 << SWS))
        ;

    RCC_CR &= ~((uint32_t)0x0001 << HSION); 
}

void systick_init(uint32_t ticks)
{
    if(ticks > 0x00FFFFFF) return;
    
    STK_CTRL = 0x0000;

    STK_VAL = ticks - 1; //ticks = interrupt period * cpu_freq - 1 (1us, 72MHz = 71)

    nvic_enable(6);
    nvic_setPriority(6, 0);

    STK_VAL = 0x0000;

    STK_CTRL = ((uint32_t)0x0001 << CLKSOURCE);
    STK_CTRL = (uint32_t)0x0001 << TICKINT;
    STK_CTRL = (uint32_t)0x0001 << STK_ENABLE;
}

extern uint32_t delay_ticks;
void usDelay(uint32_t us)
{
    delay_ticks = us;
    while(delay_ticks != 0);
}

void msDelay(uint32_t ms)
{
    delay_ticks = 1000 * ms;
    while(delay_ticks != 0);
}


