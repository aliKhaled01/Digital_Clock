/*
 * SEVENSEGMENT.h
 *
 *  Created on: Oct 2, 2021
 *      Author: lenovo
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_
#include "STD_TYPES.h"
#include "GPIO.h"
#define SEG1_ENABLE_PORT  GPIO_A
#define SEG1_ENABLE_BIN  GPIO_PIN3
#define SEG2_ENABLE_PORT  GPIO_A
#define SEG2_ENABLE_BIN   GPIO_PIN2
#define SEG3_ENABLE_PORT  GPIO_B
#define SEG3_ENABLE_PIN GPIO_PIN5
#define SEG4_ENABLE_PORT  GPIO_B
#define SEG4_ENABLE_PIN GPIO_PIN6
#define DECODER_PORT GPIO_B
#define DECODER_PIN0 GPIO_PIN0
#define DECODER_PIN1 GPIO_PIN1
#define DECODER_PIN2 GPIO_PIN2
#define DECODER_PIN3 GPIO_PIN4
typedef enum
{
	Seg1,Seg2,Seg3,Seg4
}enSegNumber;

void Seg_Init(enSegNumber number);  //init specif seg is best best practice because init all of them not good if i only want and i want to use the pins of the others in ohter things
/*
 * Description:Set Enables pins  Direction  as output
 	 	 	   Set Deconder Inputs pins direction as outputs
 	 	 	   Turn Off the enables of each seven segment " because calling the function without this step will turn on all segments with values 0
 	 	 	   because   because the enables pins will intially have zeros , decoder inputs will have intially zeros also"
 	 	 	   by default the microcontrller will give zeros to the pins"
 	 	 	   this is not good behaviour the the init function turns all segments on
 	 	 	   so solution is to disable all enables "write high" "you can use static or private function to achiecve this"
 */
void Seg_DeInit(enSegNumber number);
/* return to defalut
 *Description:Set Enables pins  Direction  as inputs
 	 	 	  write low in them "to disable the pull ip resisitor which activated from the init function"
 	 	 	  Set Deconder Inputs pins direction as inputs


 */
void Seg_Write(enSegNumber number,uint8 value);
/*
 Description: Turn on enable for this seg
 Description : Display the number
 Turning the enables on before displaying the number is a best practice because may you write and previously enable of other seg is enabled because and delay in cpu
 so you write in seg you dont need


 */
void Seg_Digital_Clock(uint8* i, uint8* j,uint8* k ,uint8* m);
void Seg_Off(enSegNumber number);
void Seg_Flashing(enSegNumber seg1, uint8 seg1_value,enSegNumber seg2, uint8 seg2_value ,uint8 seg3_value,uint8 seg4_value);
void Seg_Stop_Flashing(enSegNumber seg1, uint8 seg1_value,enSegNumber seg2, uint8 seg2_value);
#endif /* SEVENSEGMENT_H_ */
