/*
 * HighLevelComm.h
 *
 *  Created on: 2020年7月14日
 *      Author: 59488
 */

#ifndef HIGHLEVELCOMM_H_
#define HIGHLEVELCOMM_H_

#include "ClassUartTest.h"
#include "Queue.h"
#include "string.h"
#include "PWM.h"
#include "main.h"
#include <iostream>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSpeed	(100)


class HighLevelComm {
public:
		HighLevelComm(UART_HandleTypeDef& uart, TIM_HandleTypeDef& pwm);
		bool ParseMessage();
		bool Move(int x);
		bool Stop();
		bool Turn(int x);
		bool showBattery();
		bool showDistance();
		bool isRun=false;
	private:
		uint8_t myTxData_OK[5];
		uint8_t myTxData_Battery[6];
		uint8_t myTxData_Distance[6];
		Queue receivedQueue;
		char receivedCommand[100];
		uint8_t realNumber=0;
		ClassUartTest uart;
		PWM pwm;
};

#endif /* HIGHLEVELCOMM_H_ */
