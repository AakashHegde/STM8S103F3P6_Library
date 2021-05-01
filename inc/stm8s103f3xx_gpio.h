#ifndef STM8S103F3XX_GPIO_H_
#define STM8S103F3XX_GPIO_H_

#include "stm8s103f3xx.h"

/*-------------Configuration Macros-------------*/
/*----------------------------------------------*/

#define GPIO_PIN_0	0
#define GPIO_PIN_1	1
#define GPIO_PIN_2	2
#define GPIO_PIN_3	3
#define GPIO_PIN_4	4
#define GPIO_PIN_5	5
#define GPIO_PIN_6	6
#define GPIO_PIN_7	7

#define GPIO_MODE_IN	0
#define GPIO_MODE_OUT	1

#define GPIO_OUTSPD_LOW		0	//Output speed up to 2 MHz
#define GPIO_OUTSPD_HIGH	1	//Output speed up to 10 MHz

#define GPIO_OUT_TYPE_OD	0	//Output type - pseudo open drain
#define GPIO_OUT_TYPE_PP	1	//Output type - push-pull

#define GPIO_IN_TYPE_FL		0	//Input type - floating input
#define GPIO_IN_TYPE_PU		1	//Input type - with pull-up

#define GPIO_IN_IRQ_DIS		0	//Input external interrupt disabled
#define GPIO_IN_IRQ_EN		1	//Input external interrupt enabled


/*----------Configuration Structure-------------*/
/*----------------------------------------------*/

typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_OutType;
	uint8_t GPIO_OutSpeed;
	uint8_t GPIO_InType;
	uint8_t GPIO_InExtIRQEn;
}GPIO_PinConfig_t;

/*--------Peripheral Handle Structure-----------*/
/*----------------------------------------------*/

typedef struct{
	GPIO_RegDef_t *pGPIOx;				// Holds base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig;	// Holds the configuration for the GPIO pin
}GPIO_Handle_t;
	
/*---------Peripheral API Prototypes------------*/
/*----------------------------------------------*/

/* 
NOTE:
THERE IS NO ENABLE/DIABLE CAPABILITY FOR GPIO PERIPHERAL ON
THE STM8S103F3XX MCU. PERIPHERAL IS ENABLED BY DEFAULT
void GPIO_PCLKControl(GPIO_RegDef_t);
*/

//Init/De-init API
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_Handle_t *pGPIOHandle);

//Read/write API
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint8_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t PinValue);
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint8_t PinValue);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

//Interrupt API
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t Priority, uint8_t EnOrDis);
void GPIO_IRQHandler(uint8_t PinNumber);

#endif	//STM8S103F3XX_GPIO_H_