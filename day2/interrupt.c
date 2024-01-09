#include "interrupt.h"

extern unsigned int _start_text;
extern unsigned int _end_text;
extern unsigned int _stored_data;
extern unsigned int _start_data;
extern unsigned int _end_data;
extern unsigned int _start_bss;
extern unsigned int _end_bss;

extern void *_end_stack;

extern int main();

void isr_reset(void)
{
    //nvic relocate
    *((uint32_t*)SRAM_BASE) = SRAM_BASE | VECT_TAB_OFFSET;
    
    //flash init
    *((uint32_t*)FLASH_ACR) =  FLASH_ACR_RESET_VALUE;
    
    unsigned int *src, *dst, *bss;
    src = (unsigned int*)_stored_data;
    dst = (unsigned int*)_start_data;

    for(;dst < (unsigned int*)&_end_data; src++, dst++)
    {
        *dst = *src;
    }

    bss = (unsigned int*)_start_bss;

    for(;bss < (unsigned int*)_end_bss; bss++)
    {
        *bss = 0;
    }

    main();
}

__attribute__((section(".isr_vector")))
void (* const IVT[])(void) = 
{
    (void (*)(void))(&_end_stack),
    isr_reset,
    isr_nmi,
    isr_hrdfault,
    isr_memmn,
    isr_busfault,
    isr_usgfault,
    0, 0, 0, 0,
    isr_svcall,
    isr_debug_monitor,
    0,
    isr_pendsv,
    isr_systick,
    isr_wwdg,
    isr_pvd,
    isr_tamper,
    isr_rtc,
    isr_flash,
    isr_rcc,
    isr_exti0,
    isr_exti1,
    isr_exti2,
    isr_exti3,
    isr_exti4,
    isr_dma1_ch1,
    isr_dma1_ch2,
    isr_dma1_ch3,
    isr_dma1_ch4,
    isr_dma1_ch5,
    isr_dma1_ch6,
    isr_dma1_ch7,
    isr_adc1_2,
    isr_can1_tx,
    isr_can1_rx0,
    isr_can1_rx1,
    isr_can1_sce,
    isr_exti9_5,
    isr_tim1_brk,
    isr_tim1_upd,
    isr_tim1_trg_com,
    isr_tim1_cc,
    isr_tim2,
    isr_tim3,
    isr_tim4,
    isr_i2c1_ev,
    isr_i2c1_err,
    isr_i2c2_ev,
    isr_i2c2_err,
    isr_spi1,
    isr_spi2,
    isr_usart1,
    isr_usart2,
    isr_usart3,
    isr_exti5_10,
    isr_rtc_alarm,
    isr_usb_otgfs_wkup,
    0, 0, 0, 0, 0, 0, 0, 0
};

void isr_nmi(void)
{
    while(1)
    {

    }
}

void isr_hrdfault(void)
{
    while(1)
    {
        
    }
}

void isr_memmn(void)
{
    while(1)
    {
        
    }
}

void isr_busfault(void)
{
    while(1)
    {
        
    }
}

void isr_usgfault(void)
{
    while(1)
    {
        
    }
}

void isr_svcall(void)
{

}

void isr_debug_monitor(void)
{

}

void isr_pendsv(void)
{

}

/**
 * system timer : if you want to use system
*/
void isr_systick(void)
{
    //systick function needed
}

void isr_wwdg(void)
{

}

void isr_pvd(void)
{

}

void isr_tamper(void)
{

}

void isr_rtc(void)
{

}

void isr_flash(void)
{

}

void isr_rcc(void)
{

}

void isr_exti0(void)
{

}

void isr_exti1(void)
{

}

void isr_exti2(void)
{

}

void isr_exti3(void)
{

}

void isr_exti4(void)
{

}

void isr_dma1_ch1(void)
{

}

void isr_dma1_ch2(void)
{

}

void isr_dma1_ch3(void)
{

} 

void isr_dma1_ch4(void)
{

}

void isr_dma1_ch5(void)
{

}

void isr_dma1_ch6(void)
{

}

void isr_dma1_ch7(void)
{

}

void isr_adc1_2(void)
{

}

void isr_can1_tx(void)
{

}

void isr_can1_rx0(void)
{

}

void isr_can1_rx1(void)
{

}

void isr_can1_sce(void)
{

}

void isr_exti9_5(void)
{

}

void isr_tim1_brk(void)
{

}

void isr_tim1_upd(void)
{

}

void isr_tim1_trg_com(void)
{

}

void isr_tim1_cc(void)
{

}

void isr_tim2(void)
{

}

void isr_tim3(void)
{

}

void isr_tim4(void)
{

}

void isr_i2c1_ev(void)
{

}

void isr_i2c1_err(void)
{

}

void isr_i2c2_ev(void)
{

}

void isr_i2c2_err(void)
{

}

void isr_spi1(void)
{

}

void isr_spi2(void)
{

}

void isr_usart1(void)
{

}

void isr_usart2(void)
{

}

void isr_usart3(void)
{

}

void isr_exti5_10(void)
{

}

void isr_rtc_alarm(void)
{

}

void isr_usb_otgfs_wkup(void)
{

}

