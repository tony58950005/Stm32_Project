/*
 * SpeedMeasurement.h
 *
 *  Created on: 2020年11月2日
 *      Author: 59488
 */

#ifndef SPEEDMEASUREMENT_H_
#define SPEEDMEASUREMENT_H_
#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

class SpeedMeasurement {
public:
	SpeedMeasurement();
	void Encoder_Init_TIM8();
	//static void Encoder_Init_TIM4(void);
	uint8_t getTIMx_DeltaCnt(TIM_TypeDef * TIMx);
private:
	TIM_HandleTypeDef htim8;
};

#endif /* SPEEDMEASUREMENT_H_ */
