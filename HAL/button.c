/*
 * button.c
 *
 *  Created on: Sep 27, 2021
 *      Author: lenovo
 */
#include "button.h"
#include "GPIO.h"
void BUTTON_INIT(enBUTTON_NUMBER number)
{
	switch(number)
	{
	case BUTTON1 :
		GPIO_InitPin(GPIO_D,GPIO_PIN7,GPIO_INPUT);
		break;
	case BUTTON2:
		GPIO_InitPin(GPIO_D,GPIO_PIN6,GPIO_INPUT);
		break;
	case BUTTON3:
		GPIO_InitPin(GPIO_D,GPIO_PIN5,GPIO_INPUT);
		break;
	case BUTTON4:
		GPIO_InitPin(GPIO_D,GPIO_PIN4,GPIO_INPUT);
		break;

	}
}

uint8 BUTTON_GetValue(enBUTTON_NUMBER number)
{
	uint8 ret;
	switch(number)
	{
	case BUTTON1 :
		GPIO_GetPin(GPIO_D,GPIO_PIN7,&ret);
		break;
	case BUTTON2:
		GPIO_GetPin(GPIO_D,GPIO_PIN6,&ret);
		break;
	case BUTTON3:
		GPIO_GetPin(GPIO_D,GPIO_PIN5,&ret);
		break;
	case BUTTON4:
		GPIO_GetPin(GPIO_D,GPIO_PIN3,&ret);
		break;

	}
	return ret;
}
uint8 BUTTON_Edge_Status(enBUTTON_NUMBER number,enEDGE_STATUS status)
{
	static uint8 zero_flag=1;
	static uint8 high_flag=1;
	switch(status)
	{
	case RISING :
		if(BUTTON_GetValue(number)==BUTTON_PRESSED&&zero_flag==1)
		{

			zero_flag=0;
		}
		if(BUTTON_GetValue(number)==BUTTON_NOT_PRESSED&&zero_flag==0)
		{
			zero_flag=1;
			return zero_flag;

		}
		break;

	case FALLING:
		if(BUTTON_GetValue(number)==BUTTON_NOT_PRESSED&&high_flag==1)
		{
			high_flag=0;
		}
		if(BUTTON_GetValue(number)==BUTTON_PRESSED&&high_flag==0)
		{


			high_flag=1;
			return high_flag;

		}
		break;
	}

	return 0;
}

