/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 31-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : EXTI_Program.c              */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_Private.h"
#include "EXTI_Configuration.h"
#include "EXTI_Interface.h"
void EXTI_Init(void)
{
	#if Interrupt_0_Request == Enable
		SET_BIT(GICR,6);
		#if    Interrupt_0_Sense_Control == EXTI0_LowLevel
			RESET_BIT(MCUCR,1);
			RESET_BIT(MCUCR,0);
		#elif  Interrupt_0_Sense_Control == EXTI0_AnyLogicalChange
			RESET_BIT(MCUCR,1);
			SET_BIT(MCUCR,0);
		#elif  Interrupt_0_Sense_Control == EXTI0_FallingEdge
			SET_BIT(MCUCR,1);
			RESET_BIT(MCUCR,0);
		#elif  Interrupt_0_Sense_Control == EXTI0_RisingEdge
			SET_BIT(MCUCR,1);
			SET_BIT(MCUCR,0);
		#endif
	#elif Interrupt_0_Request == Disable
		RESET_BIT(GICR,6);
	#endif
	#if Interrupt_1_Request == Enable
		SET_BIT(GICR,7);
		#if    Interrupt_1_Sense_Control == EXTI1_LowLevel
			RESET_BIT(MCUCR,3);
			RESET_BIT(MCUCR,2);
		#elif  Interrupt_1_Sense_Control == EXTI1_AnyLogicalChange
			RESET_BIT(MCUCR,3);
			SET_BIT(MCUCR,2);
		#elif  Interrupt_1_Sense_Control == EXTI1_FallingEdge
			SET_BIT(MCUCR,3);
			RESET_BIT(MCUCR,2);
		#elif  Interrupt_1_Sense_Control == EXTI1_RisingEdge
			SET_BIT(MCUCR,3);
			SET_BIT(MCUCR,2);
		#endif
	#elif Interrupt_0_Request == Disable
		RESET_BIT(GICR,7);
	#endif
	#if Interrupt_2_Request == Enable
		SET_BIT(GICR,5);
		#if    Interrupt_2_Sense_Control == EXTI2_FallingEdge
			RESET_BIT(MCUCSR,6);
		#elif  Interrupt_2_Sense_Control == EXTI2_RisingEdge
			SET_BIT(MCUCSR,6);
		#endif
	#elif Interrupt_2_Request == Disable
		RESET_BIT(GICR,5);
	#endif
}
/***********************************************************************************************************/
void (*EXTI0_CallBack) (void);                //create pointer to function
void EXTI0_SetCallBack(void (*fun_ptr) (void))
{
	EXTI0_CallBack=fun_ptr;                   //pointer created equal to pointer that refer to isr function
}
void __vector_1(void) __attribute__((signal , used));
void __vector_1(void)
{
	EXTI0_CallBack();
}
/***********************************************************************************************************/
void (*EXTI1_CallBack) (void);                //create pointer to function
void EXTI1_SetCallBack(void (*fun_ptr) (void))
{
	EXTI1_CallBack=fun_ptr;                   //pointer created equal to pointer that refer to isr function
}
void __vector_2(void) __attribute__((signal , used));
void __vector_2(void)
{
	EXTI1_CallBack();
}
/***********************************************************************************************************/
void (*EXTI2_CallBack) (void);                //create pointer to function
void EXTI2_SetCallBack(void (*fun_ptr) (void))
{
	EXTI2_CallBack=fun_ptr;                   //pointer created equal to pointer that refer to isr function
}
void __vector_3(void) __attribute__((signal , used));
void __vector_3(void)
{
	EXTI2_CallBack();
}
/***********************************************************************************************************/