/*
 * PWM.cpp
 *
 *  Created on: 2020. ápr. 16.
 *      Author: Nagy Ákos
 */

#include "PWM.h"
#include "main.h"
#include "tim.h"
#include"stm32f4xx_hal_tim.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "string.h"
#include "stdint.h"

PWM::PWM(TIM_HandleTypeDef htim)
{
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_OC_InitTypeDef sConfigOC = {0};

	htim.Instance = TIM2;
	htim.Init.Prescaler = 84;
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim.Init.Period = 1000;
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim.Init.RepetitionCounter = 0;
	htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim) != HAL_OK)
	{
			Error_Handler();
	}

	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim, &sClockSourceConfig) != HAL_OK)
	{
		Error_Handler();
	}

	if (HAL_TIM_PWM_Init(&htim) != HAL_OK)

	{
		Error_Handler();
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}

	//TODO: Initialize the PWM channel using HAL_TIM_PWM_ConfigChannel function and the variable sConfigOC.
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 500;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	if(HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, TIM_CHANNEL_1)!=HAL_OK)
	{
		Error_Handler();
	}
	HAL_TIM_MspPostInit(&htim);

	if (HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_1)!=HAL_OK)
	{
		Error_Handler();
	}
}

bool PWM::setPWM(uint8_t percent)
{
	//TODO: Implement this task using a HAL function
	//TIM2->CCR1 = percent;
	if(percent>=0 && percent<=100)	//TODO-AKOS: How can be variable percent negative? I ask it, because of your code "percent>= 0".
	{
		__HAL_TIM_SET_COMPARE(&htim,TIM_CHANNEL_1, percent*10);
		return true;
	}else
	{
		return false;
	}
}

