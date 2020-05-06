
#include "stm32f4xx_hal.h"
#include "string.h"
#include "main.h"
#include "Queue.h"
#include "cstdlib"
Queue::Queue()
{
	buffer[QUEUE_MAX_SIZE];
}

bool Queue::IsBuffer_Full()
{
	return full;

}
bool Queue::IsBuffer_Empty()
{
	if((head==tail)&&(full==false))
		return 1;
	else
		return 0;
}
bool Queue::Buffer_Write(uint8_t item)//overwrite the oldest value
{
	buffer[head]=&item;
	if(full==true)
	{
		tail=(tail+1) % QUEUE_MAX_SIZE;
	}
	head=(head+1)%QUEUE_MAX_SIZE;
	if(head==tail)
		full=true;
	else
		full=false;
}
bool Queue::Buffer_Read(uint8_t* item)
{

	if(IsBuffer_Empty())
	{
		return false;
	}

	item =buffer[tail];//read the data and move the tail
	full=false;
	tail=(tail+1) % QUEUE_MAX_SIZE;
	return true;

}
uint8_t Queue::size()
{
	uint8_t size=QUEUE_MAX_SIZE;
	if(!full)
	{
		if(head>=tail)
		{
			size=(head-tail);
		}else
		{
			size=(QUEUE_MAX_SIZE+head-tail);
		}

	}
	return size;
}
