/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 2-11-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : TIMER0_Program.c            */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_Private.h"
#include "TIMER0_Configuration.h"
#include "TIMER0_Interface.h"

void TIMER0_init(void)
{
	#if   Timer0_Mode == Normal_Mode
		SET_BIT(TCCR0,7);
		RESET_BIT(TCCR0,6);
		RESET_BIT(TCCR0,3);
		#if   OC0PinBehaviourNonPWM == OC0NonPWM_Disconnect
			RESET_BIT(TCCR0,4);
			RESET_BIT(TCCR0,5);
		#elif OC0PinBehaviourNonPWM == OC0NonPWM_Toggle
			SET_BIT(TCCR0,4);
			RESET_BIT(TCCR0,5);
		#elif OC0PinBehaviourNonPWM == OC0NonPWM_Clear
			RESET_BIT(TCCR0,4);
			SET_BIT(TCCR0,5);
		#elif OC0PinBehaviourNonPWM == OC0NonPWM_Set 
			SET_BIT(TCCR0,4);
			SET_BIT(TCCR0,5);
		#endif
	#elif Timer0_Mode == PWMPhaseCorrect_Mode
		RESET_BIT(TCCR0,7);
		SET_BIT(TCCR0,6);
		RESET_BIT(TCCR0,3);
		#if	  PhaseCorrectMode == OC0PWMPhaseCorrect_Disconnect
		    RESET_BIT(TCCR0,4);
			RESET_BIT(TCCR0,5);
		#elif PhaseCorrectMode == OC0PWMPhaseCorrect_NonInvetingMode
		    RESET_BIT(TCCR0,4);
			SET_BIT(TCCR0,5);
		#elif PhaseCorrectMode == OC0PWMPhaseCorrect_InvetingMode
			SET_BIT(TCCR0,4);
			SET_BIT(TCCR0,5);
		#endif
	#elif Timer0_Mode == CTC_Mode
		SET_BIT(TCCR0,7);
		RESET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		#if   OC0PinBehaviourNonPWM == OC0NonPWM_Disconnect
			RESET_BIT(TCCR0,4);
			RESET_BIT(TCCR0,5);
		#elif OC0PinBehaviourNonPWM == OC0NonPWM_Toggle
			SET_BIT(TCCR0,4);
			RESET_BIT(TCCR0,5);
		#elif OC0PinBehaviourNonPWM == OC0NonPWM_Clear
			RESET_BIT(TCCR0,4);
			SET_BIT(TCCR0,5);
		#elif OC0PinBehaviourNonPWM == OC0NonPWM_Set 
			SET_BIT(TCCR0,4);
			SET_BIT(TCCR0,5);
		#endif
	#elif Timer0_Mode == FastPWM_Mode
		RESET_BIT(TCCR0,7);
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		#if	  FastPWMMode == OC0FastPWM_Disconnect             	         
		    RESET_BIT(TCCR0,4);
			RESET_BIT(TCCR0,5);
		#elif FastPWMMode == OC0FastPWM_NonInvetingMode           	         
		    RESET_BIT(TCCR0,4);
			SET_BIT(TCCR0,5);
		#elif FastPWMMode == OC0FastPWM_InvetingMode           	         
			SET_BIT(TCCR0,4);
			SET_BIT(TCCR0,5);
		#endif
	#endif
	
	#if   T01Prescaler == OFF
		RESET_BIT(TCCR0,0);
		RESET_BIT(TCCR0,1);
		RESET_BIT(TCCR0,2);
	#elif T01Prescaler == CLK
		SET_BIT(TCCR0,0);
		RESET_BIT(TCCR0,1);
		RESET_BIT(TCCR0,2);
	#elif T01Prescaler == CLK8
		RESET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		RESET_BIT(TCCR0,2);
	#elif T01Prescaler == CLK64
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		RESET_BIT(TCCR0,2);
	#elif T01Prescaler == CLK256
	    RESET_BIT(TCCR0,0);
		RESET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	#elif T01Prescaler == CLK1024
	    SET_BIT(TCCR0,0);
		RESET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	#elif T01Prescaler == EXTCLKF
	    RESET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	#elif T01Prescaler == EXTCLKR
	    SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	#endif
	
	#if   Timer0OutputCompareMatchInterrupt == Enable
		SET_BIT(TIMSK,1);
		OCR0=CompareValue;
	#elif Timer0OutputCompareMatchInterrupt == Disable
		RESET_BIT(TIMSK,1);
	#endif
	#if   Timer0OverFlowInterrupt == Enable
		SET_BIT(TIMSK,0);
		TCNT0=Preload;
	#elif Timer0OverFlowInterrupt == Disable
		RESET_BIT(TIMSK,0);
	#endif
	
	RESET_BIT(SFIOR,0);
}
void PWM0(u8 duty_cycle)
{
	#if   Timer0_Mode == FastPWM_Mode
		#if   FastPWMMode == OC0FastPWM_NonInvetingMode
			OCR0=((duty_cycle*256)/100)-1;
		#elif FastPWMMode == OC0FastPWM_InvetingMode
			OCR0=255-(duty_cycle*256)/100;
		#endif
	#elif Timer0_Mode == PWMPhaseCorrect_Mode
		#if   PhaseCorrectMode == OC0PWMPhaseCorrect_NonInvetingMode
			OCR0=((duty_cycle*510)/200);
		#elif PhaseCorrectMode == OC0PWMPhaseCorrect_InvetingMode
			OCR0=255-(duty_cycle*510)/200;
		#endif               
	#endif
}
/****************************************************************************************************************************************/
void (*TIMER0OutputCompareMatchInterrupt_CallBack) (void);                   //create pointer to function
void TIMER0OutputCompareMatchInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	TIMER0OutputCompareMatchInterrupt_CallBack = fun_ptr;                    //pointer created equal to pointer that refer to isr function
}
void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{
	TIMER0OutputCompareMatchInterrupt_CallBack();
}
/****************************************************************************************************************************************/
void (*TIMER0OverFlowInterrupt_CallBack) (void);                            //create pointer to function
void TIMER0OverFlowInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	TIMER0OverFlowInterrupt_CallBack = fun_ptr;                             //pointer created equal to pointer that refer to isr function
}
void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	TIMER0OverFlowInterrupt_CallBack();
}
/****************************************************************************************************************************************/