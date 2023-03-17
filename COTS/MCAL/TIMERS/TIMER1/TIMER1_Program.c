/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 6-11-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : TIMER1_Program.c            */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_Private.h"
#include "TIMER1_Configuration.h"
#include "TIMER1_Interface.h"
void TIMER1_init(void)
{
	RESET_BIT(TCCR1A,2);
	RESET_BIT(TCCR1A,3);
	SET_BIT(TCCR1B,6);
	RESET_BIT(TCCR1B,7);
	#if   Timer1_Mode == Normal
		RESET_BIT(TCCR1A,0);
		RESET_BIT(TCCR1A,1);
		RESET_BIT(TCCR1B,3);
		RESET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourNonPWM == OC1ANonPWM_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourNonPWM == OC1ANonPWM_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourNonPWM == OC1ANonPWM_ClearOnCompareMatch
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourNonPWM == OC1ANonPWM_SetOnCompareMatch 
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourNonPWM == OC1BNonPWM_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourNonPWM == OC1BNonPWM_ToggleOnCompareMatch
			SET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourNonPWM == OC1BNonPWM_ClearOnCompareMatch
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourNonPWM == OC1BNonPWM_SetOnCompareMatch 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#elif Timer1_Mode == PWMPhaseCorrect8Bit
		SET_BIT(TCCR1A,0);
		RESET_BIT(TCCR1A,1);
		RESET_BIT(TCCR1B,3);
		RESET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount 
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#elif Timer1_Mode == PWMPhaseCorrect9Bit
		RESET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		RESET_BIT(TCCR1B,3);
		RESET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount 
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#elif Timer1_Mode == PWMPhaseCorrect10Bit
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		RESET_BIT(TCCR1B,3);
		RESET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount 
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#elif Timer1_Mode == CTC
		RESET_BIT(TCCR1A,0);
		RESET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		RESET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourNonPWM == OC1ANonPWM_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourNonPWM == OC1ANonPWM_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourNonPWM == OC1ANonPWM_ClearOnCompareMatch
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourNonPWM == OC1ANonPWM_SetOnCompareMatch 
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourNonPWM == OC1BNonPWM_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourNonPWM == OC1BNonPWM_ToggleOnCompareMatch
			SET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourNonPWM == OC1BNonPWM_ClearOnCompareMatch
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourNonPWM == OC1BNonPWM_SetOnCompareMatch 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#elif Timer1_Mode == FastBWM8Bit
		SET_BIT(TCCR1A,0);
		RESET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		RESET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourFastPWMMode == OC1AFastPWM_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_NonInvetingMode
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_InvetingMode 
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourFastPWMMode == OC1BFastPWM_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourFastPWMMode == OC1BFastPWM_NonInvetingMode
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourFastPWMMode == OC1BFastPWM_InvetingMode 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#elif Timer1_Mode == FastBWM9Bit
		RESET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		RESET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourFastPWMMode == OC1AFastPWM_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_NonInvetingMode
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_InvetingMode 
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourFastPWMMode == OC1BFastPWM_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourFastPWMMode == OC1BFastPWM_NonInvetingMode
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourFastPWMMode == OC1BFastPWM_InvetingMode 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#elif Timer1_Mode == FastBWM10Bit
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		RESET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourFastPWMMode == OC1AFastPWM_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_NonInvetingMode
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_InvetingMode 
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourFastPWMMode == OC1BFastPWM_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourFastPWMMode == OC1BFastPWM_NonInvetingMode
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourFastPWMMode == OC1BFastPWM_InvetingMode 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#elif Timer1_Mode == PWMPhaseFrequencyCorrect
		SET_BIT(TCCR1A,0);
		RESET_BIT(TCCR1A,1);
		RESET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount 
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#elif Timer1_Mode == PWMPhaseCorrect
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		RESET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount 
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourPhaseCorrectMode == OC1BPWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#elif Timer1_Mode == FastBWM
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		#if   OC1APinBehaviourFastPWMMode == OC1AFastPWM_Disconnect
			RESET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_ToggleOnCompareMatch
			SET_BIT(TCCR1A,6);
			RESET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_NonInvetingMode
			RESET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		#elif OC1APinBehaviourFastPWMMode == OC1AFastPWM_InvetingMode 
			SET_BIT(TCCR1A,7);
		#endif
		#if   OC1BPinBehaviourFastPWMMode == OC1BFastPWM_Disconnect
			RESET_BIT(TCCR1A,4);
			RESET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourFastPWMMode == OC1BFastPWM_NonInvetingMode
			RESET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#elif OC1BPinBehaviourFastPWMMode == OC1BFastPWM_InvetingMode 
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
		#endif
	#endif
	
	#if   Timer1_Prescaler == OFF
		RESET_BIT(TCCR1B,0);
		RESET_BIT(TCCR1B,1);
		RESET_BIT(TCCR1B,2);
	#elif Timer1_Prescaler == CLK
		SET_BIT(TCCR1B,0);
		RESET_BIT(TCCR1B,1);
		RESET_BIT(TCCR1B,2);
	#elif Timer1_Prescaler == CLK8
		RESET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		RESET_BIT(TCCR1B,2);
	#elif Timer1_Prescaler == CLK64
		SET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		RESET_BIT(TCCR1B,2);
	#elif Timer1_Prescaler == CLK256
	    RESET_BIT(TCCR1B,0);
		RESET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	#elif Timer1_Prescaler == CLK1024
	    SET_BIT(TCCR1B,0);
		RESET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	#elif Timer1_Prescaler == EXTCLKF
	    RESET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	#elif Timer1_Prescaler == EXTCLKR
	    SET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	#endif
	
	#if   Timer1OverFlowInterrupt == Enable
		SET_BIT(TIMSK,2);
	#elif Timer1OverFlowInterrupt == Disable
		RESET_BIT(TIMSK,2);
	#endif
	#if   Timer1AOutputCompareMatchInterrupt == Enable
		SET_BIT(TIMSK,4);
	#elif Timer1AOutputCompareMatchInterrupt == Disable
		RESET_BIT(TIMSK,4);
	#endif
	#if   Timer1BOutputCompareMatchInterrupt == Enable
		SET_BIT(TIMSK,3);
	#elif Timer1BOutputCompareMatchInterrupt == Disable
		RESET_BIT(TIMSK,3);
	#endif
	#if   Timer1InputCaptureInterrupt == Enable
		SET_BIT(TIMSK,5);
	#elif Timer1InputCaptureInterrupt == Disable
		RESET_BIT(TIMSK,5);
	#endif
}
/****************************************************************************************************************************************/
void Timer1OverFlowInterrupt_Enable(void)
{
	SET_BIT(TIMSK,2);
}
void Timer1OverFlowInterrupt_Disable(void)
{
	RESET_BIT(TIMSK,2);
}
void Timer1AOutputCompareMatchInterrupt_Enable(void)
{
	SET_BIT(TIMSK,4);
}
void Timer1AOutputCompareMatchInterrupt_Disable(void)
{
	RESET_BIT(TIMSK,4);
}
void Timer1BOutputCompareMatchInterrupt_Enable(void)
{
	SET_BIT(TIMSK,3);
}
void Timer1BOutputCompareMatchInterrupt_Disable(void)
{
	RESET_BIT(TIMSK,3);
}
void Timer1InputCaptureInterrupt_Enable(void)
{
	SET_BIT(TIMSK,5);
}
void Timer1InputCaptureInterrupt_Disable(void)
{
	RESET_BIT(TIMSK,5);
}
/****************************************************************************************************************************************/
void TIMER1_Stop(void)
{
	RESET_BIT(TCCR1B,0);
	RESET_BIT(TCCR1B,1);
	RESET_BIT(TCCR1B,2);
}
void TIMER1_Start(u16 prescaler)
{
	if (prescaler == CLK)
	{
		SET_BIT(TCCR1B,0);
		RESET_BIT(TCCR1B,1);
		RESET_BIT(TCCR1B,2);
	}
	else if(prescaler == CLK8)
	{
		RESET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		RESET_BIT(TCCR1B,2);
	}
	else if(prescaler == CLK64)
	{
		SET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		RESET_BIT(TCCR1B,2);
	}
	else if(prescaler == CLK256)
	{
		RESET_BIT(TCCR1B,0);
		RESET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
	else if(prescaler == CLK1024)
	{
		SET_BIT(TCCR1B,0);
		RESET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
	else if(prescaler == EXTCLKF)
	{
		RESET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
	else if(prescaler == EXTCLKR)
	{
		SET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
}
/****************************************************************************************************************************************/
void PWM1A(u8 duty_cycle)
{
	u16 OCR1A;
	TIMER1_Stop();
	if(Timer1_Mode == FastBWM)
	{
		if(OC1APinBehaviourFastPWMMode == OC1AFastPWM_NonInvetingMode)
		{
			OCR1A=((65536*duty_cycle)/100)-1;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
		else if(OC1APinBehaviourFastPWMMode == OC1AFastPWM_InvetingMode)
		{
			OCR1A=((65536*(100-duty_cycle))/100)-1;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
	}
	else if(Timer1_Mode == FastBWM8Bit)
	{
		if(OC1APinBehaviourFastPWMMode == OC1AFastPWM_NonInvetingMode)
		{
			OCR1A=((256*duty_cycle)/100)-1;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
		else if(OC1APinBehaviourFastPWMMode == OC1AFastPWM_InvetingMode)
		{
			OCR1A=((256*(100-duty_cycle))/100)-1;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
	}
	else if(Timer1_Mode == FastBWM9Bit)
	{
		if(OC1APinBehaviourFastPWMMode == OC1AFastPWM_NonInvetingMode)
		{
			OCR1A=((512*duty_cycle)/100)-1;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
		else if(OC1APinBehaviourFastPWMMode == OC1AFastPWM_InvetingMode)
		{
			OCR1A=((512*(100-duty_cycle))/100)-1;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
	}
	else if(Timer1_Mode == FastBWM10Bit)
	{
		if(OC1APinBehaviourFastPWMMode == OC1AFastPWM_NonInvetingMode)
		{
			OCR1A=((1024*duty_cycle)/100)-1;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
		else if(OC1APinBehaviourFastPWMMode == OC1AFastPWM_InvetingMode)
		{
			OCR1A=((1024*(100-duty_cycle))/100)-1;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
	}
	else if(Timer1_Mode == PWMPhaseCorrect)
	{
		if(OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount)
		{
			OCR1A=(duty_cycle*(65536-1))/100;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
		else if(OC1APinBehaviourFastPWMMode == OC1APWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount)
		{
			OCR1A=(1-(duty_cycle/100))*(65536-1);
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
	}
	else if(Timer1_Mode == PWMPhaseCorrect8Bit)
	{
		if(OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount)
		{
			OCR1A=(duty_cycle*(256-1))/100;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
		else if(OC1APinBehaviourFastPWMMode == OC1APWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount)
		{
			OCR1A=(1-(duty_cycle/100))*(256-1);
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
	}
	else if(Timer1_Mode == PWMPhaseCorrect9Bit)
	{
		if(OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount)
		{
			OCR1A=(duty_cycle*(512-1))/100;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
		else if(OC1APinBehaviourFastPWMMode == OC1APWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount)
		{
			OCR1A=(1-(duty_cycle/100))*(512-1);
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
	}
	else if(Timer1_Mode == PWMPhaseCorrect10Bit)
	{
		if(OC1APinBehaviourPhaseCorrectMode == OC1APWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount)
		{
			OCR1A=(duty_cycle*(1024-1))/100;
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
		else if(OC1APinBehaviourFastPWMMode == OC1APWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount)
		{
			OCR1A=(1-(duty_cycle/100))*(1024-1);
			OCR1AL=(u8)OCR1A;
			OCR1AH=(u8)(OCR1A>>8);
		}
	}
	//TIMER1_Start();
}
void PWM1B(u8 duty_cycle)
{
	u16 OCR1B;
	TIMER1_Stop();
	if(Timer1_Mode == FastBWM)
	{
		if(OC1BPinBehaviourFastPWMMode == OC1BFastPWM_NonInvetingMode)
		{
			OCR1B=((65536*duty_cycle)/100)-1;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
		else if(OC1BPinBehaviourFastPWMMode == OC1BFastPWM_InvetingMode)
		{
			OCR1B=((65536*(100-duty_cycle))/100)-1;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
	}
	else if(Timer1_Mode == FastBWM8Bit)
	{
		if(OC1BPinBehaviourFastPWMMode == OC1BFastPWM_NonInvetingMode)
		{
			OCR1B=((256*duty_cycle)/100)-1;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
		else if(OC1BPinBehaviourFastPWMMode == OC1BFastPWM_InvetingMode)
		{
			OCR1B=((256*(100-duty_cycle))/100)-1;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
	}
	else if(Timer1_Mode == FastBWM9Bit)
	{
		if(OC1BPinBehaviourFastPWMMode == OC1BFastPWM_NonInvetingMode)
		{
			OCR1B=((512*duty_cycle)/100)-1;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
		else if(OC1BPinBehaviourFastPWMMode == OC1BFastPWM_InvetingMode)
		{
			OCR1B=((512*(100-duty_cycle))/100)-1;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
	}
	else if(Timer1_Mode == FastBWM10Bit)
	{
		if(OC1BPinBehaviourFastPWMMode == OC1BFastPWM_NonInvetingMode)
		{
			OCR1B=((1024*duty_cycle)/100)-1;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
		else if(OC1BPinBehaviourFastPWMMode == OC1BFastPWM_InvetingMode)
		{
			OCR1B=((1024*(100-duty_cycle))/100)-1;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
	}
	else if(Timer1_Mode == PWMPhaseCorrect)
	{
		if(OC1BPinBehaviourFastPWMMode == OC1BPWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount)
		{                                 
			OCR1B=(duty_cycle*(65536-1))/100;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
		else if(OC1BPinBehaviourFastPWMMode == OC1BPWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount)
		{
			OCR1B=(1-(duty_cycle/100))*(65536-1);
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
	}
	else if(Timer1_Mode == PWMPhaseCorrect8Bit)
	{
		if(OC1BPinBehaviourFastPWMMode == OC1BPWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount)
		{
			OCR1B=(duty_cycle*(256-1))/100;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
		else if(OC1BPinBehaviourFastPWMMode == OC1BPWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount)
		{
			OCR1B=(1-(duty_cycle/100))*(256-1);
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
	}
	else if(Timer1_Mode == PWMPhaseCorrect9Bit)
	{
		if(OC1BPinBehaviourFastPWMMode == OC1BPWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount)
		{
			OCR1B=(duty_cycle*(512-1))/100;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
		else if(OC1BPinBehaviourFastPWMMode == OC1BPWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount)
		{
			OCR1B=(1-(duty_cycle/100))*(512-1);
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
	}
	else if(Timer1_Mode == PWMPhaseCorrect10Bit)
	{
		if(OC1BPinBehaviourFastPWMMode == OC1BPWMPhaseCorrect_ClearOnCompareMatchUpCountSetOnCompareMatchDownCount)
		{
			OCR1B=(duty_cycle*(1024-1))/100;
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
		else if(OC1BPinBehaviourFastPWMMode == OC1BPWMPhaseCorrect_SetOnCompareMatchUpCountClearOnCompareMatchDownCount)
		{
			OCR1B=(1-(duty_cycle/100))*(1024-1);
			OCR1BL=(u8)OCR1B;
			OCR1BH=(u8)(OCR1B>>8);
		}
	}
	//TIMER1_Start();
}
/****************************************************************************************************************************************/
void (*TIMER1AOutputCompareMatchInterrupt_CallBack) (void);                   //create pointer to function
void TIMER1AOutputCompareMatchInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	TIMER1AOutputCompareMatchInterrupt_CallBack = fun_ptr;                    //pointer created equal to pointer that refer to isr function
}
void __vector_7(void) __attribute__((signal , used));
void __vector_7(void)
{
	TIMER1AOutputCompareMatchInterrupt_CallBack();
}
/****************************************************************************************************************************************/
void (*TIMER1BOutputCompareMatchInterrupt_CallBack) (void);                   //create pointer to function
void TIMER1BOutputCompareMatchInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	TIMER1AOutputCompareMatchInterrupt_CallBack = fun_ptr;                    //pointer created equal to pointer that refer to isr function
}
void __vector_8(void) __attribute__((signal , used));
void __vector_8(void)
{
	TIMER1BOutputCompareMatchInterrupt_CallBack();
}
/****************************************************************************************************************************************/
void (*TIMER1OverFlowInterrupt_CallBack) (void);                            //create pointer to function
void TIMER1OverFlowInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	TIMER1OverFlowInterrupt_CallBack = fun_ptr;                             //pointer created equal to pointer that refer to isr function
}
void __vector_9(void) __attribute__((signal , used));
void __vector_9(void)
{
	TIMER1OverFlowInterrupt_CallBack();
}
/****************************************************************************************************************************************/
void (*Timer1InputCaptureInterrupt_CallBack) (void);                            //create pointer to function
void Timer1InputCaptureInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	Timer1InputCaptureInterrupt_CallBack = fun_ptr;                             //pointer created equal to pointer that refer to isr function
}
void __vector_6(void) __attribute__((signal , used));
void __vector_6(void)
{
	Timer1InputCaptureInterrupt_CallBack();
}
/****************************************************************************************************************************************/