/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 9-1-2023     		   		 */
/*	Version: 0.1				         */
/*	File   : SPI_Program.c               */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "SPI_Private.h"
#include "SPI_Configuration.h"
#include "SPI_Interface.h"
/****************************************************************************************************************************************/
void SPIMaster_Init(void)
{
	SET_BIT(DDRB,4);
	SET_BIT(PORTB,4);
	SET_BIT(DDRB,5);
	RESET_BIT(DDRB,6);
	SET_BIT(DDRB,7);
	SPITransferCompleteInterrupt_Disable();
	SPI_Enable();
	#if DataOrder == LSBTransFirst
		SET_BIT(SPCR,5);
	#elif DataOrder == MSBTransFirst 
		RESET_BIT(SPCR,5);
	#endif
	SET_BIT(SPCR,4);
	#if ClockPolarity == LeadingEdgeRisingTrailingEdgeFalling
		RESET_BIT(SPCR,3);
	#elif ClockPolarity == LeadingEdgeFallingTrailingEdgeRising 
		SET_BIT(SPCR,3);
	#endif
	#if ClockPhase == LeadingEdgeSampleTrailingEdgeSetup
		RESET_BIT(SPCR,2);
	#elif ClockPhase == LeadingEdgeSetupTrailingEdgeSample  
		SET_BIT(SPCR,2);
	#endif
	#if ClockRate == FoscDiv4
		RESET_BIT(SPCR,0);
		RESET_BIT(SPCR,1);
		RESET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv16
		SET_BIT(SPCR,0);
		RESET_BIT(SPCR,1);
		RESET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv64
		RESET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		RESET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv128
		SET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		RESET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv2
		RESET_BIT(SPCR,0);
		RESET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv8
		SET_BIT(SPCR,0);
		RESET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv32
		RESET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv64
		SET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	#endif
	
}
/****************************************************************************************************************************************/
void SPISlave_Init(void)
{
	RESET_BIT(DDRB,4);
	RESET_BIT(DDRB,5);
	SET_BIT(DDRB,6);
	RESET_BIT(DDRB,7);
	SPITransferCompleteInterrupt_Disable();
	SPI_Enable();
	#if DataOrder == LSBTransFirst
		SET_BIT(SPCR,5);
	#elif DataOrder == MSBTransFirst 
		RESET_BIT(SPCR,5);
	#endif
	RESET_BIT(SPCR,4);
	#if ClockPolarity == LeadingEdgeRisingTrailingEdgeFalling
		RESET_BIT(SPCR,3);
	#elif ClockPolarity == LeadingEdgeFallingTrailingEdgeRising 
		SET_BIT(SPCR,3);
	#endif
	#if ClockPhase == LeadingEdgeSampleTrailingEdgeSetup
		RESET_BIT(SPCR,2);
	#elif ClockPhase == LeadingEdgeSetupTrailingEdgeSample  
		SET_BIT(SPCR,2);
	#endif
	#if ClockRate == FoscDiv4
		RESET_BIT(SPCR,0);
		RESET_BIT(SPCR,1);
		RESET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv16
		SET_BIT(SPCR,0);
		RESET_BIT(SPCR,1);
		RESET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv64
		RESET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		RESET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv128
		SET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		RESET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv2
		RESET_BIT(SPCR,0);
		RESET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv8
		SET_BIT(SPCR,0);
		RESET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv32
		RESET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	#elif ClockRate == FoscDiv64
		SET_BIT(SPCR,0);
		SET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	#endif
	
}
/****************************************************************************************************************************************/
void SPI_Enable(void)
{
	SET_BIT(SPCR,6);
}
/****************************************************************************************************************************************/
void SPI_Disable(void)
{
	RESET_BIT(SPCR,6);
}
/****************************************************************************************************************************************/
void SPIMaster_Send(u8 Data)
{
	u8 Flush;
	RESET_BIT(PORTB,4);
	SPDR = Data;
	while(((SPSR>>7)&1)==0);
	Flush = SPDR;
	SET_BIT(PORTB,4);
}
/****************************************************************************************************************************************/
u8 SPIMaster_Receive(void)
{
	u8 Dummy = 0x00;
	SPDR = Dummy;
	while(((SPSR>>7)&1)==0);
	return SPDR;
}
/****************************************************************************************************************************************/
void SPISlave_Send(u8 Data)
{
	
	
}
/****************************************************************************************************************************************/
u8 SPISlave_Receive(void)
{
	u8 Dummy = 0x00;
	SPDR = Dummy;
	while(((SPSR>>7)&1)==0);
	return SPDR;
}
/****************************************************************************************************************************************/
void SPITransferCompleteInterrupt_Enable(void)
{
	SET_BIT(SPCR,7);
}
/****************************************************************************************************************************************/
void SPITransferCompleteInterrupt_Disable(void)
{
	RESET_BIT(SPCR,7);
}
/****************************************************************************************************************************************/
void (*SPITransferCompleteInterrupt_CallBack) (void);                   //create pointer to function
void SPITransferCompleteInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	SPITransferCompleteInterrupt_CallBack = fun_ptr;                    //pointer created equal to pointer that refer to isr function
}
void __vector_12(void) __attribute__((signal , used));
void __vector_12(void)
{
	SPITransferCompleteInterrupt_CallBack();
}
/****************************************************************************************************************************************/