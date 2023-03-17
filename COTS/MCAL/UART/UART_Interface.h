/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 8-1-2023     		   		 */
/*	Version: 0.1				         */
/*	File   : UART_Interface.h            */
/*****************************************/

#ifndef _UART_INTERFACE_H_
#define _UART_INTERFACE_H_

void UART_Init(void);
void UART_ReceiveEnable(void);
void UART_ReceiveDisable(void);
void UART_TransmitEnable(void);
void UART_TransmitDisable(void);
void UART_Send(u8);
u8 UART_Receive(void);
void UARTRxCompleteInterrupt_Enable(void);
void UARTRxCompleteInterrupt_Disable(void);
void UARTRxCompleteInterrupt_SetCallBack(void (*fun_ptr) (void));
void UARTTxCompleteInterrupt_Enable(void);
void UARTTxCompleteInterrupt_Disable(void);
void UARTTxCompleteInterrupt_SetCallBack(void (*fun_ptr) (void));
void UARTDataRegEmptyInterrupt_Enable(void);
void UARTDataRegEmptyInterrupt_Disable(void);
void UARTDataRegEmptyInterrupt_SetCallBack(void (*fun_ptr) (void));

#endif