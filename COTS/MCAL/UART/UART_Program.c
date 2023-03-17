/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 8-1-2023     		   		 */
/*	Version: 0.1				         */
/*	File   : UART_Program.c              */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Private.h"
#include "UART_Configuration.h"
#include "UART_Interface.h"
/****************************************************************************************************************************************/
void UART_Init(void)
{
	/*Baud Rate*/
	RESET_BIT(UBRRH,7);
	UBRRH = (u8)(BaudRate>>8);
	UBRRL = (u8)(BaudRate);
	/*Enabling Transmit & Receive*/
	UART_ReceiveEnable();
	UART_TransmitEnable();
	/*Data Size*/
	#if SizeOfData == FiveBits
	SET_BIT(UCSRC,7);
	RESET_BIT(UCSRC,1);
	RESET_BIT(UCSRC,2);
	RESET_BIT(UCSRB,2);
	#elif SizeOfData == SixBits
	SET_BIT(UCSRC,7);
	SET_BIT(UCSRC,1);
	RESET_BIT(UCSRC,2);
	RESET_BIT(UCSRB,2);
	#elif SizeOfData == SevenBits
	SET_BIT(UCSRC,7);
	RESET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	RESET_BIT(UCSRB,2);
	#elif SizeOfData == EightBits
	SET_BIT(UCSRC,7);
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	RESET_BIT(UCSRB,2);
	#elif SizeOfData == NineBits
	SET_BIT(UCSRC,7);
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	SET_BIT(UCSRB,2);
	#endif
	/*Parity Check*/
	#if ParityMode == Disable
	SET_BIT(UCSRC,7);
	RESET_BIT(UCSRC,4);
	RESET_BIT(UCSRC,5);
	#elif parityMode == Even
	SET_BIT(UCSRC,7);
	RESET_BIT(UCSRC,4);
	SET_BIT(UCSRC,5);
	#elif ParityMode == Odd
	SET_BIT(UCSRC,7);
	SET_BIT(UCSRC,4);
	SET_BIT(UCSRC,5);
	#endif
	/*Stop Bit*/
	#if StopBit == OneBit
	SET_BIT(UCSRC,7);
	RESET_BIT(UCSRC,3);
	#elif StopBit == TwoBits
	SET_BIT(UCSRC,7);
	SET_BIT(UCSRC,3);
	#endif
	/*UART Mode*/
	#if UARTMode == Asynchronous
		SET_BIT(UCSRC,7);
		RESET_BIT(UCSRC,6);
		/*UART Transmition Speed*/
		#if UARTTrasmitionSpeed == NormalSpeed
			RESET_BIT(UCSRA,1);
		#elif UARTTrasmitionSpeed == DoubleSpeed
			SET_BIT(UCSRA,1);
		#endif
	#elif UARTMode == Synchronous
		SET_BIT(UCSRC,7);
		SET_BIT(UCSRA,6);
		RESET_BIT(UCSRA,1);
		/*Clock Polarity in case of UART Synchronous Mode*/
		#if ClockPolarity == RisingEdge
			RESET_BIT(UCSRC,0);
		#elif ClockPolarity == FallingEdge
			SET_BIT(UCSRA,0);
		#endif
	#endif
	/*Multi Processor Communication Mode*/
	#if UARTMultiProcessorComunicationMode == Disable
		RESET_BIT(UCSRA,0);
	#elif UARTMultiProcessorComunicationMode == Enable
		SET_BIT(UCSRA,0);
	#endif
}
/****************************************************************************************************************************************/
void UART_ReceiveEnable(void)
{
	SET_BIT(UCSRB,4);
}
/****************************************************************************************************************************************/
void UART_ReceiveDisable(void)
{
	RESET_BIT(UCSRB,4);
}
/****************************************************************************************************************************************/
void UART_TransmitEnable(void)
{
	SET_BIT(UCSRB,3);
}
/****************************************************************************************************************************************/
void UART_TransmitDisable(void)
{
	RESET_BIT(UCSRB,3);
}
/****************************************************************************************************************************************/
void UART_Send(u8 Data)
{
	/* Wait for data to be sent*/
	while ((((UCSRA>>6)&1)==0)&&(((UCSRA>>5)&1)==0));
	/* Put data into buffer, sends the data */
	UDR = Data;
}
/****************************************************************************************************************************************/
u8 UART_Receive(void)
{
	/* Wait for data to be received */
	while ((((UCSRA>>7)&1)==0)&&(((UCSRA>>5)&1)==1));
	/* Get and return received data from buffer */
	return UDR;
}
/****************************************************************************************************************************************/
void UARTRxCompleteInterrupt_Enable(void)
{
	SET_BIT(UCSRB,7);
}
/****************************************************************************************************************************************/
void UARTRxCompleteInterrupt_Disable(void)
{
	RESET_BIT(UCSRB,7);
}
/****************************************************************************************************************************************/
void (*UARTRxCompleteInterrupt_CallBack) (void);                   //create pointer to function
void UARTRxCompleteInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	UARTRxCompleteInterrupt_CallBack = fun_ptr;                    //pointer created equal to pointer that refer to isr function
}
void __vector_13(void) __attribute__((signal , used));
void __vector_13(void)
{
	UARTRxCompleteInterrupt_CallBack();
}
/****************************************************************************************************************************************/
void UARTTxCompleteInterrupt_Enable(void)
{
	SET_BIT(UCSRB,6);
}
/****************************************************************************************************************************************/
void UARTTxCompleteInterrupt_Disable(void)
{
	RESET_BIT(UCSRB,6);
}
/****************************************************************************************************************************************/
void (*UARTTxCompleteInterrupt_CallBack) (void);                   //create pointer to function
void UARTTxCompleteInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	UARTTxCompleteInterrupt_CallBack = fun_ptr;                    //pointer created equal to pointer that refer to isr function
}
void __vector_15(void) __attribute__((signal , used));
void __vector_15(void)
{
	UARTTxCompleteInterrupt_CallBack();
}
/****************************************************************************************************************************************/
void UARTDataRegEmptyInterrupt_Enable(void)
{
	SET_BIT(UCSRB,5);
}
/****************************************************************************************************************************************/
void UARTDataRegEmptyInterrupt_Disable(void)
{
	RESET_BIT(UCSRB,5);
}
/****************************************************************************************************************************************/
void (*UARTDataRegEmptyInterrupt_CallBack) (void);                   //create pointer to function
void UARTDataRegEmptyInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	UARTDataRegEmptyInterrupt_CallBack = fun_ptr;                    //pointer created equal to pointer that refer to isr function
}
void __vector_14(void) __attribute__((signal , used));
void __vector_14(void)
{
	UARTDataRegEmptyInterrupt_CallBack();
}
/****************************************************************************************************************************************/