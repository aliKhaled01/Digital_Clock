/*
 * SEVENSEGMENT.c
 *
 *  Created on: Oct 2, 2021
 *      Author: lenovo
 */

#include "SEVENSEGMENT.h"
#include "GPIO.h"
#include "STD_TYPES.h"
#include "utiles.h"
#include <util/delay.h>

void Seg_Init(enSegNumber number)
{
	GPIO_InitPin( DECODER_PORT,DECODER_PIN0,GPIO_OUTPUT);
	GPIO_InitPin( DECODER_PORT,DECODER_PIN1,GPIO_OUTPUT);
	GPIO_InitPin( DECODER_PORT,DECODER_PIN2,GPIO_OUTPUT);
	GPIO_InitPin( DECODER_PORT,DECODER_PIN3,GPIO_OUTPUT);

	switch(number)
	{
	case Seg1:
		GPIO_InitPin(SEG1_ENABLE_PORT,SEG1_ENABLE_BIN,GPIO_OUTPUT);
		GPIO_WritePin(SEG1_ENABLE_PORT,SEG1_ENABLE_BIN,GPIO_HIGH); //Turn Off Enables
		break;
	case Seg2:
		GPIO_InitPin(SEG2_ENABLE_PORT,SEG2_ENABLE_BIN,GPIO_OUTPUT);
		GPIO_WritePin(SEG2_ENABLE_PORT,SEG2_ENABLE_BIN,GPIO_HIGH); //Turn Off Enables
		break;
	case Seg3:
		GPIO_InitPin(SEG3_ENABLE_PORT,SEG3_ENABLE_PIN,GPIO_OUTPUT);
		GPIO_WritePin(SEG3_ENABLE_PORT,SEG3_ENABLE_PIN,GPIO_HIGH); //Turn Off Enables
		break;
	case Seg4:
		GPIO_InitPin(SEG4_ENABLE_PORT,SEG4_ENABLE_PIN,GPIO_OUTPUT);
		GPIO_WritePin(SEG4_ENABLE_PORT,SEG4_ENABLE_PIN,GPIO_HIGH); //Turn Off Enables
		break;

	}

}
void Seg_Write(enSegNumber number,uint8 value)
{
	// i need only one segment works at at time so each time go here disable all of them
	//then write at only one


	GPIO_WritePin(SEG1_ENABLE_PORT,SEG1_ENABLE_BIN,GPIO_HIGH);
	GPIO_WritePin(SEG2_ENABLE_PORT,SEG2_ENABLE_BIN,GPIO_HIGH); //Turn Off Enables
	GPIO_WritePin(SEG3_ENABLE_PORT,SEG3_ENABLE_PIN,GPIO_HIGH); //Turn Off Enables
	GPIO_WritePin(SEG4_ENABLE_PORT,SEG4_ENABLE_PIN,GPIO_HIGH); //Turn Off Enables

	switch(number)
	{
	case Seg1:
		GPIO_WritePin(SEG1_ENABLE_PORT,SEG1_ENABLE_BIN,GPIO_LOW);
		break;
	case Seg2:
		GPIO_WritePin(SEG2_ENABLE_PORT,SEG2_ENABLE_BIN,GPIO_LOW);
		break;
	case Seg3:
		GPIO_WritePin(SEG3_ENABLE_PORT , SEG3_ENABLE_PIN ,GPIO_LOW);
		break;
	case Seg4:
		GPIO_WritePin(SEG4_ENABLE_PORT ,SEG4_ENABLE_PIN ,GPIO_LOW);
		break;
	}
	GPIO_WritePin(DECODER_PORT,DECODER_PIN0,GET_BIT(value,0));
	GPIO_WritePin(DECODER_PORT,DECODER_PIN1,GET_BIT(value,1));
	GPIO_WritePin(DECODER_PORT,DECODER_PIN2,GET_BIT(value,2));
	GPIO_WritePin(DECODER_PORT,DECODER_PIN3,GET_BIT(value,3));
}

void Seg_Digital_Clock(uint8* i, uint8* j,uint8* k ,uint8* m)
{
	for((*j)=0; (*j)<=6;(*j)++)
	{
		for( (*i)=0; (*i)<=9;(*i)++)
		{
			if((*j)==6)
			{
				for(sint32 y=1; y<=30;y++)
				{
					Seg_Write(Seg1,0);
					_delay_ms(5);
					Seg_Write(Seg2,(*j));
					_delay_ms(5);
					Seg_Write(Seg3,(*k));
					_delay_ms(5);
					Seg_Write(Seg4,(*m));
					_delay_ms(5);
				}
				if((*m)==2&&(*k)==3)
				{
					(*i)=0;
					(*k)=0;
				}
				else if((*k)<9){
					(*k)++;
				}
				else if((*k)==9&&(*m)<2)
				{
					(*k)=0;
					(*m)++;
				}

				break;

			}
			else
			{
				for(sint32 u=1; u<=30;u++)
				{
					Seg_Write(Seg1,(*i));
					_delay_ms(5);
					Seg_Write(Seg2,(*j));
					_delay_ms(5);
					Seg_Write(Seg3,(*k));
					_delay_ms(5);
					Seg_Write(Seg4,(*m));
					_delay_ms(5);
				}
			}
		}

	}
}


void Seg_Off(enSegNumber number)
{
	switch(number)
	{
	case Seg1:
		GPIO_WritePin(SEG1_ENABLE_PORT,SEG1_ENABLE_BIN,GPIO_HIGH);
		break;
	case Seg2:
		GPIO_WritePin(SEG2_ENABLE_PORT,SEG2_ENABLE_BIN,GPIO_HIGH);
		break;
	case Seg3:
		GPIO_WritePin(SEG3_ENABLE_PORT , SEG3_ENABLE_PIN ,GPIO_HIGH);
		break;
	case Seg4:
		GPIO_WritePin(SEG4_ENABLE_PORT ,SEG4_ENABLE_PIN ,GPIO_HIGH);
		break;
	}
}

void Seg_Flashing(enSegNumber seg1, uint8 seg1_value,enSegNumber seg2, uint8 seg2_value,uint8 seg3_value,uint8 seg4_value )
{
	for(uint8 j=0; j<10	; j++ )
	{
	for(uint8 h=0; h<48;h++)
	{
		Seg_Write(seg1,seg1_value);
		_delay_ms(5);
		Seg_Write(seg2,seg2_value);
		_delay_ms(5);
		Seg_Write(Seg3,seg3_value);
		_delay_ms(5);
		Seg_Write(Seg4,seg4_value);
		_delay_ms(5);

	}
	Seg_Off(Seg1);
	Seg_Off(Seg2);
	for(uint8 h=0; h<48;h++)
	{

		Seg_Write(Seg3,seg3_value);
		_delay_ms(10);
		Seg_Write(Seg4,seg4_value);
		_delay_ms(10);
	}

	}
}
void Seg_Stop_Flashing(enSegNumber seg1, uint8 seg1_value,enSegNumber seg2, uint8 seg2_value)
{
	Seg_Write(seg1,seg1_value);
	_delay_ms(10);
	Seg_Write(seg2,seg2_value);
	_delay_ms(10);


}

