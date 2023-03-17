/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 8-1-2023   		   		 */
/*	Version: 0.1				         */
/*	File   : UART_Private.h	             */
/*****************************************/

#ifndef _UART_PRIVATE_H_
#define _UART_PRIVATE_H_

#define UDR  	*((volatile u8*)0x2C)
#define UCSRA 	*((volatile u8*)0x2B)
#define UCSRB   *((volatile u8*)0x2A)
#define UCSRC   *((volatile u8*)0x40)
#define UBRRH   *((volatile u8*)0x40)
#define UBRRL   *((volatile u8*)0x29)
/*UART Trasmition Speed */
#define NormalSpeed  0
#define DoubleSpeed  1
/*UART MultiProcessor Comunication Mode*/
#define Disable      0
#define Enable       1
/*Size Of Data*/
#define FiveBits     0
#define SixBits      1
#define SevenBits    2
#define EightBits    3
#define NineBits     7
/*UART Mode */
#define Asynchronous 0
#define Synchronous  1
/*Parity Mode*/
#define Even         2
#define Odd          3
/*Stop Bit*/
#define OneBit       0
#define TwoBits      1
/*Clock Polarity in case of UART Synchronous Mode*/
#define RisingEdge   0
#define FallingEdge  1

#endif

