/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 2-11-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : TIMER0_Private.h	         */
/*****************************************/

#ifndef _TIMER0_PRIVATE_H_
#define _TIMER0_PRIVATE_H_

#define TCCR0      *((volatile u8*)0x53)      //Timer counter control register
#define TCNT0      *((volatile u8*)0x52)      //Timer counter register
#define OCR0       *((volatile u8*)0x5C)      //Output compare register
#define TIMSK      *((volatile u8*)0x59)      //Timer counter interrupt mask register
#define TIFR       *((volatile u8*)0x58)      //Timer counter interrupt flag register
#define SFIOR      *((volatile u8*)0x50)      //Special function input output register

//Timer0 Modes
#define Normal_Mode                      	0
#define PWMPhaseCorrect_Mode             	1
#define CTC_Mode                        	2
#define FastPWM_Mode                     	3

//OC0 pin Behaviour in non-PWM Mode at compare match
#define OC0NonPWM_Disconnect             	0
#define OC0NonPWM_Toggle                 	1  
#define OC0NonPWM_Clear                  	2
#define OC0NonPWM_Set                    	3

//PWM Phase Correct Mode
#define OC0PWMPhaseCorrect_Disconnect       0
#define OC0PWMPhaseCorrect_NonInvetingMode  2
#define OC0PWMPhaseCorrect_InvetingMode     3

//Fast PWM Mode
#define OC0FastPWM_Disconnect           	0
#define OC0FastPWM_NonInvetingMode       	2
#define OC0FastPWM_InvetingMode          	3

//Prescaler
#define OFF                              	0
#define CLK                              	1
#define CLK8                            	2
#define CLK64                           	3
#define CLK256                          	4
#define CLK1024                         	5
#define EXTCLKF                          	6
#define EXTCLKR                          	7

#define Enable                           	1
#define Disable                          	0

#endif

