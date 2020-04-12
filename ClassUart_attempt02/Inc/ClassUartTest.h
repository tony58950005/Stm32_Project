/*
 * ClassUartTest.h
 *
 *  Created on: Mar. 22, 2020
 *      Author: 59488
 */

#ifndef CLASSUARTTEST_H_
#define CLASSUARTTEST_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include "usart.h"
#include "string.h"
#include "main.h"
#define UART_DEFAULT_TIMEOUT	(100)

#ifdef __cplusplus
class ClassUartTest
{
	public:
		ClassUartTest(UART_HandleTypeDef huart);
		bool 	sendMessage(uint8_t* buffer, uint32_t bufferLength, uint32_t timeout = UART_DEFAULT_TIMEOUT);
		bool	receiveMessage(uint8_t* buffer, uint32_t bufferLength, uint32_t timeout = UART_DEFAULT_TIMEOUT);
	private:
		UART_HandleTypeDef huart;
};
#endif
#endif /* CLASSUARTTEST_H_ */
