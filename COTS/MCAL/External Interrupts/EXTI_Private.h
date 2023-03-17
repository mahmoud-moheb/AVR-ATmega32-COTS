/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 31-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : EXTI_Private.h	             */
/*****************************************/

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#define MCUCR   *((volatile u8*)0x55)
#define MCUCSR  *((volatile u8*)0x54)
#define GICR    *((volatile u8*)0x5B)
#define GIFR    *((volatile u8*)0x5A)

#define EXTI0_LowLevel          0
#define EXTI0_AnyLogicalChange  1
#define EXTI0_FallingEdge       2
#define EXTI0_RisingEdge        3

#define EXTI1_LowLevel          0
#define EXTI1_AnyLogicalChange  1
#define EXTI1_FallingEdge       2
#define EXTI1_RisingEdge        3

#define EXTI2_FallingEdge       0
#define EXTI2_RisingEdge        1

#define Enable                  1
#define Disable                 0

#endif

