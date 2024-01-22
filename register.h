/*
 * register.h
 *
 *  Created on: Jan 15, 2024
 *      Author: shipg
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include <stdint.h>
#include <stdbool.h>

/*
 * Memory map base
 **/
#define SRAM_BASE				((uint32_t)0x20000000)
#define SYSTICK_BASE			((uint32_t)0xE000E010)
#define PERIPHERAL_BASE			((uint32_t)0x40000000)
#define NVIC_BASE				((uint32_t)0xE000E100)
#define NVIC_IPR_BASE			(NVIC_BASE + 0x300)

#define APB1PERIPH_BASE			PERIPHERAL_BASE
#define APB2PERIPH_BASE			(PERIPHERAL_BASE + 0x10000)
#define AHBPERIPH_BASE			(PERIPHERAL_BASE + 0x20000) //exclude sdio + reserved(bit band alias)

#define GPIOA_BASE				(APB2PERIPH_BASE + 0x0800)
#define AFIO_BASE				(APB2PERIPH_BASE + 0x0000)
#define EXTI_BASE				(APB2PERIPH_BASE + 0x0400)
#define RCC_BASE				(AHBPERIPH_BASE + 0x1000)
#define FLASH_BASE				(AHBPERIPH_BASE + 0x2000)
#define TIM2_BASE				(APB1PERIPH_BASE + 0x0000)


/*
 * Register Map
 * */
typedef struct
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
} GPIO_type;

typedef struct
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
} RCC_type;

typedef struct
{
	uint32_t ACR;
	uint32_t KEYR;
	uint32_t OPTKEYR;
	uint32_t SR;
	uint32_t CR;
	uint32_t AR;
	uint32_t RESERVED;
	uint32_t OBR;
	uint32_t WRPR;
} FLASH_type;

typedef struct
{
	uint32_t CTRL;
	uint32_t LOAD;
	uint32_t VAL;
	uint32_t CALIB;
} STK_type;

typedef struct
{
	uint32_t IMR;
	uint32_t EMR;
	uint32_t RTSR;
	uint32_t FTSR;
	uint32_t SWIER;
	uint32_t PR;
} EXTI_type;

typedef struct
{
	uint32_t ISER0;
	uint32_t ISER1;
	uint32_t ISER2;

	uint32_t ICER0;
	uint32_t ICER1;
	uint32_t ICER2;

	uint32_t ISPR0;
	uint32_t ISPR1;
	uint32_t ISPR2;

	uint32_t ICPR0;
	uint32_t ICPR1;
	uint32_t ICPR2;

	uint32_t IABR0;
	uint32_t IABR1;
	uint32_t IABR2;
}NVIC_type;

typedef struct
{
	uint32_t EVCR;
	uint32_t MAPR;
	uint32_t EXTICR1;
	uint32_t EXTICR2;
	uint32_t EXTICR3;
	uint32_t EXTICR4;
	uint32_t MAPR2;
} AFIO_type;

typedef struct
{
	uint32_t CR1;
	uint32_t CR2;
	uint32_t SMCR;
	uint32_t DIER;
	uint32_t SR;
	uint32_t EGR;
	uint32_t CCMR1;
	uint32_t CCMR2;
	uint32_t CCER;
	uint32_t CNT;
	uint32_t PSC;
	uint32_t ARR;
	uint32_t reserved_1;
	uint32_t CCR1;
	uint32_t CCR2;
	uint32_t CCR3;
	uint32_t CCR4;
	uint32_t reserved_2;
	uint32_t DCR;
	uint32_t DMAR;
} TIM_type;

/**
 * Memory address
 * */
#define GPIOA			((volatile GPIO_type  *) GPIOA_BASE)
#define GPIOB			((volatile GPIO_type  *)(GPIOA_BASE + 0x400))
#define GPIOC			((volatile GPIO_type  *)(GPIOA_BASE + 0x800))
#define GPIOD			((volatile GPIO_type  *)(GPIOA_BASE + 0xC00))
#define GPIOE			((volatile GPIO_type  *)(GPIOA_BASE + 0x1000))
#define GPIOF			((volatile GPIO_type  *)(GPIOA_BASE + 0x1400))
#define GPIOG			((volatile GPIO_type  *)(GPIOA_BASE + 0x1800))

#define AFIO			((volatile AFIO_type  *) AFIO_BASE)

#define RCC				((volatile RCC_type   *)   RCC_BASE)
#define FLASH			((volatile FLASH_type *) FLASH_BASE)
#define STK				((volatile STK_type *) SYSTICK_BASE)
#define EXTI			((volatile EXTI_type *)   EXTI_BASE)
#define NVIC			((volatile NVIC_type *)   NVIC_BASE)
#define TIM2			((volatile TIM_type *) TIM2_BASE)
#endif /* REGISTER_H_ */
