/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 6-11-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : TIMER1_Private.h	         */
/*****************************************/

#ifndef _TIMER1_PRIVATE_H_
#define _TIMER1_PRIVATE_H_

#define TCCR1A      *((volatile u8*)0x4F)      //Timer/counter 1 control register A
#define TCCR1B      *((volatile u8*)0x4E)      //Timer/counter 1 control register B

#define TCNT1H      *((volatile u8*)0x4D)      //Timer/counter 1 High
#define TCNT1L      *((volatile u8*)0x4C)      //Timer/counter 1 Low

#define OCR1AH      *((volatile u8*)0x4B)      //Output compare register 1 A High
#define OCR1AL      *((volatile u8*)0x4A)      //Output compare register 1 A Low

#define OCR1BH      *((volatile u8*)0x49)      //Output compare register 1 B High
#define OCR1BL      *((volatile u8*)0x48)      //Output compare register 1 B Low

#define ICR1H       *((volatile u8*)0x47)      //Input capture register 1  High
#define ICR1L       *((volatile u8*)0x46)      //Input capture register 1  Low

#define TIMSK       *((volatile u8*)0x59)      //Timer counter interrupt Mask register
#define TIFR        *((volatile u8*)0x58)      //Timer counter interrupt flag register

//Timer1 Modes
#define Normal                              										0
#define PWMPhaseCorrect8Bit  														1
#define PWMPhaseCorrect9Bit   			    										2
#define PWMPhaseCorrect10Bit    													3
#define CTC                     													4
#define FastBWM8Bit  																5
#define FastBWM9Bit   			    												6
#define FastBWM10Bit    															7
#define PWMPhaseFrequencyCorrect    	    										9
#define PWMPhaseCorrect                     										11
#define FastBWM                             										15


//OC1A pin Behaviour in non-PWM Mode at compare match
#define OC1ANonPWM_Disconnect             											0
#define OC1ANonPWM_ToggleOnCompareMatch                 							1  
#define OC1ANonPWM_ClearOnCompareMatch                  							2
#define OC1ANonPWM_SetOnCompareMatch                      							3

//OC1B pin Behaviour in non-PWM Mode at compare match
#define OC1BNonPWM_Disconnect             											0
#define OC1BNonPWM_ToggleOnCompareMatch                 							1  
#define OC1BNonPWM_ClearOnCompareMatch                  							2
#define OC1BNonPWM_SetOnCompareMatch                    							3 

//OC1A Compare Output Mode Fast PWM
#define OC1AFastPWM_Disconnect           											0
#define OC1AFastPWM_ToggleOnCompareMatch    										1
#define OC1AFastPWM_NonInvetingMode       											2
#define OC1AFastPWM_InvetingMode          											3

//OC1B Compare Output Mode Fast PWM
#define OC1BFastPWM_Disconnect           											0
#define OC1BFastPWM_NonInvetingMode       											2
#define OC1BFastPWM_InvetingMode          											3

//OC1A Compare Output Phase Correct Mode
#define OC1APWMPhaseCorrect_Disconnect      										0		
#define OC1APWMPhaseCorrect_ToggleOnCompareMatch         						    1
#define OC1APWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount 	2
#define OC1APWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount    3

//OC1B Compare Output Phase Correct Mode
#define OC1BPWMPhaseCorrect_Disconnect       										0
#define OC1BPWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount  	2
#define OC1BPWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount     3

//Prescaler
#define OFF                              											0
#define CLK                              											1
#define CLK8                            											8
#define CLK64                           											64
#define CLK256                          											256
#define CLK1024                         											1024
#define EXTCLKF                          											3
#define EXTCLKR                          											4

#define Enable                           											1
#define Disable                          											0

#endif

