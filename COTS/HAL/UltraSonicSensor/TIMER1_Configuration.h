/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 6-11-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : TIMER1_Configuration.h      */
/*****************************************/

#ifndef _TIMER1_CONFIGURATION_H_
#define _TIMER1_CONFIGURATION_H_

#define Timer1_Mode                      	             Normal 
#define Timer1_Prescaler                    			 OFF 
#define Timer1OverFlowInterrupt             			 Disable
#define Timer1AOutputCompareMatchInterrupt   			 Disable
#define Timer1BOutputCompareMatchInterrupt   			 Disable
#define Timer1InputCaptureInterrupt          			 Disable
/********************************************************************************************************************************/	
#define OC1APinBehaviourNonPWM             	 			 OC1ANonPWM_Disconnect 
#define OC1BPinBehaviourNonPWM             	 			 OC1BNonPWM_Disconnect
/********************************************************************************************************************************/	
#define OC1APinBehaviourPhaseCorrectMode    	         OC1APWMPhaseCorrect_Disconnect	   //PWM frequency = crystal frequency/(Prescaler*((2^n)-2))
																						   //OCR0_nonInvertedMode = (duty cycle * ((2^n)-1))/100
                                                                                           //OCR0InvertedMode = (1-(duty cycle/100))*((2^n)-1) 
#define OC1BPinBehaviourPhaseCorrectMode    	         OC1BPWMPhaseCorrect_Disconnect 	   //PWM frequency = crystal frequency/(Prescaler*((2^n)-2))
                                                                                           //OCR0_nonInvertedMode = (duty cycle * ((2^n)-1))/100
                                                                                           //OCR0InvertedMode = (1-(duty cycle/100))*((2^n)-1)  																			   
/********************************************************************************************************************************/																				   
#define OC1APinBehaviourFastPWMMode             	     OC1AFastPWM_Disconnect            //PWM frequency = crystal frequency/(Prescaler*2^n)
                                                                                           //OCR1A_nonInvertedMode =((duty cycle * 2^n)/100)-1
                                                                                           //OCR1B_InvertedMode = ((2^n*(100-duty cycle))/100)-1  
#define OC1BPinBehaviourFastPWMMode             	     OC1BFastPWM_Disconnect            //PWM frequency = frequency/(Prescaler*2^n)
                                                                                           //OCR1A_nonInvertedMode =((duty cycle * 2^n)/100)-1
                                                                                           //OCR1B_InvertedMode = ((2^n*(100-duty cycle))/100)-1           
/********************************************************************************************************************************/																			   
#endif