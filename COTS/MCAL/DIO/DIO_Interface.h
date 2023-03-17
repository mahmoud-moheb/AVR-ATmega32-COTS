/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 25-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : DIO_Interface.h             */
/*****************************************/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

void DIO_Init(void);
void Set_Bit(volatile u8*,u8);
void Reset_Bit(volatile u8*,u8);
void Toggle_Bit(volatile u8*,u8);

#endif