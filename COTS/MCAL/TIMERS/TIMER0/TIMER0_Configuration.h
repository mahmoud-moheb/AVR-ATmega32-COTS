/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 2-11-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : TIMER0_Configuration.h      */
/*****************************************/

#ifndef _TIMER0_CONFIGURATION_H_
#define _TIMER0_CONFIGURATION_H_

#define Timer0_Mode                      	 Normal_Mode  
#define OC0PinBehaviourNonPWM             	 OC0NonPWM_Disconnect
#define PhaseCorrectMode    	             OC0PWMPhaseCorrect_Disconnect	   //PWM frequency=crystal frequency/(Prescaler*510)
                                                                               //OCR0_nonInvertedMode=(duty cycle * 510)/200
                                                                               //OCR0InvertedMode=255-((duty cycle * 510)/200 )  
																			   
#define FastPWMMode             	         OC0FastPWM_Disconnect             //PWM frequency=crystal frequency/(Prescaler*256)
                                                                               //OCR0_nonInvertedMode=((duty cycle * 256)/100)-1
                                                                               //OCR0InvertedMode=255-(duty cycle * 256)/100           
#define T01Prescaler                         CLK  
#define Timer0OutputCompareMatchInterrupt    Disable
#define CompareValue                         0x00
#define Timer0OverFlowInterrupt              Enable
#define Preload                              0x00

#endif