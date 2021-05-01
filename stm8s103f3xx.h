#ifndef STM8S103F3XX_H_
#define STM8S103F3XX_H_

#include <stdint.h>

#define _VO volatile

/*Generic macros*/
#define HIGH 		1
#define LOW 		0
#define SET 		HIGH
#define RESET 		LOW
#define ENABLE 		1
#define DISABLE 	0

/*Register Base Address*/
#define HW_REG_BASEADDR		0x005000U	//GPIO Register Base Address
#define CLK_REG_BASEADDR	0x0050C0U	//Clock Register Base Address


/*GPIO Port Base Addresses*/
#define GPIOA_BASEADDR		(HW_REG_BASEADDR)
#define GPIOB_BASEADDR		(HW_REG_BASEADDR + 0x0005)
#define GPIOC_BASEADDR		(HW_REG_BASEADDR + 0x000A)
#define GPIOD_BASEADDR		(HW_REG_BASEADDR + 0x000F)
#define GPIOE_BASEADDR		(HW_REG_BASEADDR + 0x0014)
#define GPIOF_BASEADDR		(HW_REG_BASEADDR + 0x0019)


/*---------------Peripheral Register Structures---------------*/
/*------------------------------------------------------------*/

//GPIO Register Structure
typedef struct{
	_VO uint8_t ODR;		//Output data register
	_VO uint8_t IDR;		//Pin input register
	_VO uint8_t DDR;		//Data direction register
	_VO uint8_t CR1;		//Control register 1
	_VO uint8_t CR2;		//Control register 2
}GPIO_RegDef_t;

//CLK Register Structure
typedef struct{
	_VO uint8_t ICKR;		//Internal clock register
	_VO uint8_t ECKR;		//External clock register
	uint8_t RESERVED;
	_VO uint8_t CMSR;		//Clock master status register
	_VO uint8_t SWR;		//Clock master switch register
	_VO uint8_t SWCR;		//Switch control register
	_VO uint8_t CKDIVR;		//Clock divider register 
	_VO uint8_t PCKENR1;	//Peripheral clock gating register 1
	_VO uint8_t PCKENR2;	//Peripheral clock gating register 2
	_VO uint8_t CSSR;		//Clock security system register
	_VO uint8_t CCOR;		//Configurable clock output register
	_VO uint8_t HSITRIMR;	//HSI clock calibration trimming register
	_VO uint8_t SWIMCCR;	//SWIM clock control register
}CLK_RegDef_t;

/*-----------------Peripheral Definitions---------------------*/
/*------------------------------------------------------------*/

#define GPIOA 	(GPIO_RegDef_t*)GPIOA_BASEADDR
#define GPIOB 	(GPIO_RegDef_t*)GPIOB_BASEADDR
#define GPIOC 	(GPIO_RegDef_t*)GPIOC_BASEADDR
#define GPIOD 	(GPIO_RegDef_t*)GPIOD_BASEADDR
#define GPIOE 	(GPIO_RegDef_t*)GPIOE_BASEADDR
#define GPIOF 	(GPIO_RegDef_t*)GPIOF_BASEADDR

#define CLK 	(CLK_RegDef_t*)CLK_REG_BASEADDR

/*-------------Clock Enalble Macros for Peripherals-----------*/
/*------------------------------------------------------------*/

#define I2C_PCLK_EN()	(CLK->PCKENR1 |= (1<<0))
#define SPI_PCLK_EN()	(CLK->PCKENR1 |= (1<<1))
#define UART1_PCLK_EN()	(CLK->PCKENR1 |= (1<<3))
#define TIM4_PCLK_EN()	(CLK->PCKENR1 |= (1<<4))
#define TIM2_PCLK_EN()	(CLK->PCKENR1 |= (1<<5))
#define TIM1_PCLK_EN()	(CLK->PCKENR1 |= (1<<7))
#define AWU_PCLK_EN()	(CLK->PCKENR2 |= (1<<2))
#define ADC_PCLK_EN()	(CLK->PCKENR2 |= (1<<3))

/*-------------Clock Disalble Macros for Peripherals-----------*/
/*-------------------------------------------------------------*/

#define I2C_PCLK_DIS()		(CLK->PCKENR1 &= ~(1<<0))
#define SPI_PCLK_DIS()		(CLK->PCKENR1 &= ~(1<<1))
#define UART1_PCLK_DIS()	(CLK->PCKENR1 &= ~(1<<3))
#define TIM4_PCLK_DIS()		(CLK->PCKENR1 &= ~(1<<4))
#define TIM2_PCLK_DIS()		(CLK->PCKENR1 &= ~(1<<5))
#define TIM1_PCLK_DIS()		(CLK->PCKENR1 &= ~(1<<7))
#define AWU_PCLK_DIS()		(CLK->PCKENR2 &= ~(1<<2))
#define ADC_PCLK_DIS()		(CLK->PCKENR2 &= ~(1<<3))

/*----------------------Peripheral Includes-------------------*/
/*------------------------------------------------------------*/

#include "stm8s103f3xx_gpio.h"

#endif //STM8S103F3XX_H_