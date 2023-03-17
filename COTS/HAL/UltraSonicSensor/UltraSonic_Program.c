/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 25-2-2023   		   		 */
/*	Version: 0.1				         */
/*	File   : UltraSonic_program.c	     */
/*****************************************/
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_Configuration.h"
#include "DIO_Interface.h"
#include "GlobalInterrupt_Private.h"
#include "GlobalInterrupt_Configuration.h"
#include "GlobalInterrupt_Interface.h"
#include "TIMER1_Private.h"
#include "TIMER1_Configuration.h"
#include "TIMER1_Interface.h"
#include "ULTRASONIC_Private.h"
#include "ULTRASONIC_Configuration.h"
#include "ULTRASONIC_Interface.h"
u32 flag = 1;
u32 counter=0;
f32 Distance_cm=0;
u16 ICR=0;
u16 t=0;
u16 t1Low=0;
u16 t1=0;
u16 t2Low=0;
u16 t2=0;
char Distance_cm_ToChar[1];
void InputCaptureInterruptHandler(void)
{
	if(flag == 1)
	{
		t1Low=ICR1L;
		t1=(ICR1H<<8);
		t1+=t1Low;
		TCCR1B&=~(1<<6);//negative edge
		flag=0;
		TIFR|=(1<<5);//reset flag
		counter++;
		return;
	}
	else if(flag == 0)
	{
		TCCR1B=0x40;//positive and stop
		Timer1InputCaptureInterrupt_Disable();//stop input capture interrupt
		t2Low=ICR1L;
		t2=(ICR1H<<8);
		t2+=t2Low; 
		flag=1;
		TIFR|=(1<<5);//reset flag
		counter++;
		return;
	}
}
void UltraSonic_Init(void)
{
	DDRD|=(1<<3);		/*DDRD PIN 3 OUTPUT for TRIG*/
	PORTD&=~(1<<3);		/*RESET PORTD PIN 3*/
	DDRD&=~(1<<6);		/*DDRD PIN 6 INPUT for ECHO*/
	TIMER1_init();
	TIMER1_Start(8);
	Timer1InputCaptureInterrupt_SetCallBack(InputCaptureInterruptHandler);
	GlobalInterrupt_Enable();
}
f32 UltraSonic_GetDistance(void)
{
	counter=0;
	TCNT1L=0x00;
	TCNT1H=0x00;
	TIMER1_Start(8);
	PORTD|=(1<<3);		/*set PORTD PIN 3*/
	_delay_us(10);
	PORTD&=~(1<<3);		/*RESET PORTD PIN 3*/
	Timer1InputCaptureInterrupt_Enable();
	while(counter!=2);
	counter=0;
	t=t2-t1;
	Distance_cm=(0.034*(float)t)/2.0;
	//itoa((int)Distance_cm,Distance_cm_ToChar,10);
	return Distance_cm;
}