/*
 * HighLevelComm.h
 *
 *  Created on: 2020年7月14日
 *      Author: 59488
 */

#ifndef HIGHLEVELCOMM_H_
#define HIGHLEVELCOMM_H_

#include "ADCClass.h"
#include "ClassUartTest.h"
#include "PIDController.h"
#include "SpeedMeasurement.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f407xx.h"
#include "Queue.h"
#include "string.h"
#include "PWM.h"
#include "main.h"
#include <iostream>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSpeed	(100)
extern uint8_t ErrorInfo[33];


class HighLevelComm {
public:
		HighLevelComm(UART_HandleTypeDef& uart, PWM servoPWM, PWM motorPWM1, PWM motorPWM2);
		bool ParseMessage();
		bool Move(int x);
		bool Stop();
		bool Turn(int x);
		bool showBattery();
		bool showDistance();
		bool Delay(int x);
		bool setSteering(PWM& servoPWM, float steeringAngle);
		bool controlSpeed(PID_Controller& motor, float referenceSpeed, float actualSpeed);
		bool getMotorSpeed();
		bool measureDistance();
		//uint8_t *copy(uint8_t array[], uint8_t a[], uint8_t b[], uint8_t n, uint8_t m);
		bool isRun=false;
	private:
		uint8_t myTxData_OK[5];
		uint8_t myTxData_Battery[6];
		char myTxData_Distance[50];
		float distanceR,distanceL,distanceM;
		Queue receivedQueue;
		char receivedCommand[100];
		uint8_t realNumber=0;
		ClassUartTest uart;
		PWM servoPWM;
		PID_Controller motor;
		SpeedMeasurement motorSpeed;
		ADCClass adc;
		uint8_t realSpeed;
		uint8_t WheelEncoderNow    = 0;
	//	uint8_t rightWheelEncoderNow   = 0;
		uint8_t WheelEncoderLast   = 0;
	//	uint8_t rightWheelEncoderLast  = 0;

};

#endif /* HIGHLEVELCOMM_H_ */
