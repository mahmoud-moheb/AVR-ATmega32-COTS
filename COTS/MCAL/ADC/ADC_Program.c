/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 31-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : ADC_Program.c               */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Private.h"
#include "ADC_Configuration.h"
#include "ADC_Interface.h"

void ADC_Init(void)
{	
	#if VREF == AREF
		RESET_BIT(ADMUX,7);
		RESET_BIT(ADMUX,6);
	#elif VREF == AVCC
		RESET_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
	#elif VREF == Internal_VREF
		SET_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
	#endif
	#if ADC_ResultAdjust == LeftAdjust
		SET_BIT(ADMUX,5);
	#elif ADC_ResultAdjust == RightAdjust
		RESET_BIT(ADMUX,5);
	#endif
	
	SET_BIT(ADCSRA,7);   //ADC Enable
	SET_BIT(ADCSRA,5);   //Auto Trigger Disable
	RESET_BIT(ADCSRA,3); //ADC Interrupt Disable
	SET_BIT(ADCSRA,2);   /*************************/
	SET_BIT(ADCSRA,0);   /*ADC PreScaler Selection*/
	SET_BIT(ADCSRA,1);   /*************************/
	
	RESET_BIT(SFIOR,7);  /*************************/ 
	RESET_BIT(SFIOR,6);  /*ADC Auto Trigger Source*/
	RESET_BIT(SFIOR,5);  /*   free running mode   */
	RESET_BIT(SFIOR,4);  /*************************/	
}
u16 ADC_Result(u8 Channel_Num)
{
	u16 ADC_value=0,ADC_Low=0;
	
	ADMUX     = ADMUX|((u8) Channel_Num & 0b00001111);	/* Set input channel to read                     */
	SET_BIT(ADCSRA,6);                           		/* Start conversion                              */
	while(GET_BITVAL(ADCSRA,4)==0);	               	    /* wait while conversion complete                */
	if(ADC_ResultAdjust==LeftAdjust)
	{
		ADC_Low   = ((u16)ADCL>>6);		                /* Read lower 2 bits and and right it left by 6  */
		ADC_value = ((u16)ADCH<<2);		                /* Read higher byte and and shift it left by 2   */
		ADC_value = ADC_value | ADC_Low;
	}
	else if(ADC_ResultAdjust==RightAdjust)
	{
		ADC_Low   = (u16)ADCL;		                    /* Read lower byte                               */
		ADC_value = (u16)ADCH*256;		            	/* Read higher 2 bits and and shift it left by 8 */
		ADC_value = ADC_value + ADC_Low;
	}			
	return(ADC_value);			                	    /* Return digital value                          */
}