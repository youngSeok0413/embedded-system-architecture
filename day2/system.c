#include "register.h"

//nvic enable
void nvic_enable(uint8_t n)
{
    switch (n/32)
    {
    case 0:
        NVIC_ISER0 |= (1 << (n%32));
        break;
    case 1:
        NVIC_ISER1 |= (1 << (n%32));
        break;
    case 2:
        NVIC_ISER2 |= (1 << (n%32));
        break;
    
    default:
        break;
    }
}

//nvic disable
void nvic_disable(uint8_t n)
{
    switch (n/32)
    {
    case 0:
        NVIC_ICER0 |= (1 << (n%32));
        break;
    case 1:
        NVIC_ICER1 |= (1 << (n%32));
        break;
    case 2:
        NVIC_ICER2 |= (1 << (n%32));
        break;
    
    default:
        break;
    }
}

//nvic set priority
void nvic_setPriority(uint8_t n, uint8_t priority)
{
    volatile uint8_t *nvic_ipri = (volatile uint8_t*)(NVIC_IPRX_BASE + n);
    *nvic_ipri = priority;
}

//flash set waitstate
void flash_set_waitstates(void)
{
    uint32_t value;
    value = 2 | (1 << 3) | (1 << 4);
    FLASH_ACR |= value;

    while((FLASH_ACR & (1 << 5)) != 1);

    return;
}

