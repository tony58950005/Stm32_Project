/*
 * ErrorState.h
 *
 *  Created on: 2020年10月14日
 *      Author: 59488
 */

#ifndef ERRORSTATE_H_
#define ERRORSTATE_H_

//class ErrorState {
//};
enum Error
{
	NoError,
	PWMError,
	ADCError,
	HighLevelCommError,
	UartError,
	AssertFailError
};
extern Error NowState;

#endif /* ERRORSTATE_H_ */
