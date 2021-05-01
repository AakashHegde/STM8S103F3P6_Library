#include "stm8s103f3xx_gpio.h"

//Initialize GPIO
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint8_t pinOffset = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
	
	//Configure pin mode
	pGPIOHandle->pGPIOx->DDR &= ~(1 << pinOffset); //Clear the bit
	pGPIOHandle->pGPIOx->DDR |= ((pGPIOHandle->GPIO_PinConfig.GPIO_PinMode) << pinOffset);
	
	//If pin is to be configured as an input pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IN)
	{
		//Configure input type for pin  - floating / with pull-up
		pGPIOHandle->pGPIOx->CR1 &= ~(1 << pinOffset); //Clear the bit
		pGPIOHandle->pGPIOx->CR1 |= ((pGPIOHandle->GPIO_PinConfig.GPIO_InType) << pinOffset);
		//Configure whether external inputs are enabled on the pin
		pGPIOHandle->pGPIOx->CR2 &= ~(1 << pinOffset); //Clear the bit
		pGPIOHandle->pGPIOx->CR2 |= ((pGPIOHandle->GPIO_PinConfig.GPIO_InExtIRQEn) << pinOffset);
	}
	//If pin is to be configured as an output pin
	else
	{
		//Configure output type for pin  - pseudo open-drain / push-pull
		pGPIOHandle->pGPIOx->CR1 &= ~(1 << pinOffset); //Clear the bit
		pGPIOHandle->pGPIOx->CR1 |= ((pGPIOHandle->GPIO_PinConfig.GPIO_OutType) << pinOffset);
		//Configure output speed
		pGPIOHandle->pGPIOx->CR2 &= ~(1 << pinOffset); //Clear the bit
		pGPIOHandle->pGPIOx->CR2 |= ((pGPIOHandle->GPIO_PinConfig.GPIO_OutSpeed) << pinOffset);
	}
}

void GPIO_DeInit(GPIO_Handle_t *pGPIOHandle)
{
	uint8_t pinOffset = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
	//Reset DDR
	pGPIOHandle->pGPIOx->DDR &= ~(0xFF);
	
	//Reset CR1
	if(pGPIOHandle->pGPIOx == GPIOD)
	{
		pGPIOHandle->pGPIOx->CR1 &= ~(0xFD);
	}
	else
	{
		pGPIOHandle->pGPIOx->CR1 &= ~(0xFF);
	}
	
	//Reset CR2
	pGPIOHandle->pGPIOx->CR1 &= ~(0xFF);
}

//Read pin
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	return (uint8_t)(((pGPIOx->IDR) >> PinNumber) & 0x01);
}

//Read port
uint8_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx)
{
	return (uint8_t)(pGPIOx->IDR);
}

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t PinValue)
{
	if(PinValue == HIGH)
		pGPIOx->ODR |= (1 << PinNumber);
	else
		pGPIOx->ODR &= ~(1 << PinNumber);
}

void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint8_t PinValue)
{
	pGPIOx->ODR = PinValue;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

//Interrupt API
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t Priority, uint8_t EnOrDis);
void GPIO_IRQHandler(uint8_t PinNumber);