/*
 * register.h
 *
 *  Created on: Jan 15, 2024
 *      Author: shipg
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include <stdint.h>

/*
 * Memory map base
 **/
#define SRAM_BASE				((uint32_t)0x20000000)
#define SYSTICK_BASE			((uint32_t)0xE000E010)
#define PERIPHERAL_BASE			((uint32_t)0x40000000)

#define APB1PERIPH_BASE			PERIPHERAL_BASE
#define APB2PERIPH_BASE			(PERIPHERAL_BASE + 0x10000)
#define AHBPERIPH_BASE			(PERIPHERAL_BASE + 0x20000) //exclude sdio + reserved(bit band alias)

#define GPIOA_BASE				(APB2PERIPH_BASE + 0x0800)
#define RCC_BASE				(AHBPERIPH_BASE + 0x1000)
#define FLASH_BASE				(AHBPERIPH_BASE + 0x2000)

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

/**
 * Memory address
 * */
#define GPIOA			((volatile GPIO_type  *) GPIOA_BASE)
#define GPIOB			((volatile GPIO_type  *) GPIOA_BASE + 0x400)
#define GPIOC			((volatile GPIO_type  *) GPIOA_BASE + 0x800)
#define GPIOD			((volatile GPIO_type  *) GPIOA_BASE + 0xC00)
#define GPIOE			((volatile GPIO_type  *) GPIOA_BASE + 0x1000)
#define GPIOF			((volatile GPIO_type  *) GPIOA_BASE + 0x1400)
#define GPIOG			((volatile GPIO_type  *) GPIOA_BASE + 0x1800)

#define RCC				((volatile RCC_type   *)   RCC_BASE)
#define FLASH			((volatile FLASH_type *) FLASH_BASE)
#define STK				((volatile STK_type *) SYSTICK_BASE)

#endif /* REGISTER_H_ */
