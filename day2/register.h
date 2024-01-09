/**
 *Contain basic address information, bitmask functions, and bit banding function
*/
#pragma once

#include <stdint.h>

//sram
#define SRAM_BASE          (*(volatile uint32_t*)0x20000000)
#define VECT_TAB_OFFSET    ((uint32_t)0x00000000)


//flash
#define FLASH_BASE          ((uint32_t)0x40022000)
#define FLASH_ACR           (*((volatile uint32_t*)(FLASH_BASE + 0x00)))
#define FLASH_KEYR          (*((volatile uint32_t*)(FLASH_BASE + 0x04)))
#define FLASH_OPTKEYR          (*((volatile uint32_t*)(FLASH_BASE + 0x08)))
#define FLASH_SR          (*((volatile uint32_t*)(FLASH_BASE + 0x0C)))
#define FLASH_CR          (*((volatile uint32_t*)(FLASH_BASE + 0x10)))
#define FLASH_AR          (*((volatile uint32_t*)(FLASH_BASE + 0x14)))
#define FLASH_OBR          (*((volatile uint32_t*)(FLASH_BASE + 0x1C)))
#define FLASH_WRPR          (*((volatile uint32_t*)(FLASH_BASE + 0x20)))

//private peripheral bus
#define NVIC_BASE            ((uint32_t)0xE000E100)

/*nvic register : iser */

//nvic iser
#define NVIC_ISER0          (*((volatile uint32_t*)(NVIC_BASE + 0x00)))
#define NVIC_ISER1          (*((volatile uint32_t*)(NVIC_BASE + 0x04)))
#define NVIC_ISER2          (*((volatile uint32_t*)(NVIC_BASE + 0x08)))
//nvic icer
#define NVIC_ICER0          (*((volatile uint32_t*)(NVIC_BASE + 0x80)))
#define NVIC_ICER1          (*((volatile uint32_t*)(NVIC_BASE + 0x84)))
#define NVIC_ICER2          (*((volatile uint32_t*)(NVIC_BASE + 0x88)))
//nvic ispr
#define NVIC_ISPR0          (*((volatile uint32_t*)(NVIC_BASE + 0x100)))
#define NVIC_ISPR1          (*((volatile uint32_t*)(NVIC_BASE + 0x104)))
#define NVIC_ISPR2          (*((volatile uint32_t*)(NVIC_BASE + 0x108)))
//nvic icpr
#define NVIC_ICPR0          (*((volatile uint32_t*)(NVIC_BASE + 0x180)))
#define NVIC_ICPR1          (*((volatile uint32_t*)(NVIC_BASE + 0x184)))
#define NVIC_ICPR2          (*((volatile uint32_t*)(NVIC_BASE + 0x188)))
//nvic iabr
#define NVIC_IABR0          (*((volatile uint32_t*)(NVIC_BASE + 0x200)))
#define NVIC_IABR1          (*((volatile uint32_t*)(NVIC_BASE + 0x204)))
#define NVIC_IABR2          (*((volatile uint32_t*)(NVIC_BASE + 0x208)))
//nvic ipr0
#define NVIC_IPRX_BASE           NVIC_BASE + 0x300
//nvic stir
#define NVIC_STIR           (*(volatile uint32_t*)(0xE000EF00 + 0xE00))

/**
 * System Control Block
*/
#define SCB_BASE            ((uint32_t) 0xE000ED00)
//#define SCB_BASE            ((uint32_t)  0xE000E008) for stm32f2, stm32fl
//scb actlr 
//The ACTLR register disables certain aspects of functionality within the processor. 
//This register is available in STM32F2 and STM32L series.
//#define SCB_ACTLR           (*((volatile uint32_t*)(SCB_BASE + 0x00)))

//SCB_CPUID - stm32f1 series
#define SCB_CPUID           (*((volatile uint32_t*)(SCB_BASE + 0x00)))
//SCB_ICSR
#define SCB_ICSR           (*((volatile uint32_t*)(SCB_BASE + 0x04)))
//scb vtor
#define SCB_VTOR           (*((volatile uint32_t*)(SCB_BASE + 0x08)))
//SCB_AIRCR
#define SCB_AIRCR           (*((volatile uint32_t*)(SCB_BASE + 0x0C)))
//SCB_SCR
#define SCB_SCR           (*((volatile uint32_t*)(SCB_BASE + 0x10)))
//SCB_CCR
#define SCB_CCR           (*((volatile uint32_t*)(SCB_BASE + 0x14)))
//SCB_SHPR1
#define SCB_SHPR1           (*((volatile uint32_t*)(SCB_BASE + 0x18)))
//SCB_SHPR2
#define SCB_SHPR2           (*((volatile uint32_t*)(SCB_BASE + 0x1C)))
//SCB_SHPR3
#define SCB_SHPR3           (*((volatile uint32_t*)(SCB_BASE + 0x20)))
//SCB_SHCRS
#define SCB_SHCRS           (*((volatile uint32_t*)(SCB_BASE + 0x24)))
//SCB_CFSR
#define SCB_CFSR           (*((volatile uint32_t*)(SCB_BASE + 0x28)))
//SCB_HFSR
#define SCB_HFSR           (*((volatile uint32_t*)(SCB_BASE + 0x2C)))
//SCB_MMAR
#define SCB_MMAR           (*((volatile uint32_t*)(SCB_BASE + 0x34)))
//SCB_BFAR
#define SCB_BFAR           (*((volatile uint32_t*)(SCB_BASE + 0x38)))

/**
 * clock register
*/
#define RCC_BASE            ((uint32_t)0x40021000)
//RCC_CR
#define RCC_CR          (*(uint32_t*)(RCC_BASE + 0x00))
//RCC_CFGR
#define RCC_CFGR          (*(uint32_t*)(RCC_BASE + 0x04))
//RCC_CIR
#define RCC_CIR          (*(uint32_t*)(RCC_BASE + 0x08))
//RCC_APB2RSTR
#define RCC_APB2RSTR          (*(uint32_t*)(RCC_BASE + 0x0C))
//RCC_APB1RSTR
#define RCC_APB1RSTR          (*(uint32_t*)(RCC_BASE + 0x10))
//RCC_AHBENR
#define RCC_AHBENR          (*(uint32_t*)(RCC_BASE + 0x14))
//RCC_APB2ENR
#define RCC_APB2ENR          (*(uint32_t*)(RCC_BASE + 0x18))
//RCC_APB1ENR
#define RCC_APB1ENR          (*(uint32_t*)(RCC_BASE + 0x1C))
//RCC_BDCR
#define RCC_BDCR          (*(uint32_t*)(RCC_BASE + 0x20))
//RCC_BDCR
#define RCC_CSR          (*(uint32_t*)(RCC_BASE + 0x24))


/**
 * SysTick timer : processor has 24 bit system timer (count down to zero)
*/
#define STK_BASE            ((uint32_t)0xE000E010)
//STK_CTRL
#define STK_CTRL            (*(uint32_t*)(STK_BASE + 0x00))
//STK_LOAD
#define STK_LOAD            (*(uint32_t*)(STK_BASE + 0x04))
//STK_VAL
#define STK_VAL            (*(uint32_t*)(STK_BASE + 0x08))
//STK_CALIB
#define STK_CALIB            (*(uint32_t*)(STK_BASE + 0x0C))