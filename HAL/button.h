/*
 * button.h
 *
 *  Created on: Sep 27, 2021
 *      Author: lenovo
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include "STD_TYPES.h"
#define BUTTON_NOT_PRESSED  1
#define BUTTON_PRESSED      0
#define ACTIVED            	1
#define NOT_ACTIVED        0
typedef enum
{
	BUTTON1,BUTTON2,BUTTON3,BUTTON4
}enBUTTON_NUMBER;
typedef enum
{
	 RISING,FALLING
}enEDGE_STATUS;
void BUTTON_INIT(enBUTTON_NUMBER number);
/*
 * Name: BUTTON_INIT(enBUTTON_NUMBER)
 * Input: BUTTON{1...4}
 * Description : BUTTON_INIT INPUT_PIN
 */

uint8 BUTTON_GetValue(enBUTTON_NUMBER number);
/*
 * Name: BUTTON_GetValue(enBUTTON_NUMBER number)
 * Input: BUTTON{1..4}
 * Description : BUTTON_GetValue PinValue
 * Output:
 	 	 	 BUTTON_PRESSED     0
 	 	 	 BUTTON_NOT_PRESSED 1
 */
uint8 BUTTON_Edge_Status(enBUTTON_NUMBER number,enEDGE_STATUS);
/*
 * Name: BUTTON_RisingEdge(enBUTTON_NUMBER number)
 *Input: BUTTON{1..4}
 *Input: {RISING , FALLING}
 *Descripion : determine specific button status (Rising or Falling) is actived or not
 *Output: ACTIVED  		1
 *Output: NOT_ACTIVED 	0
 */

#endif /* BUTTON_H_ */
