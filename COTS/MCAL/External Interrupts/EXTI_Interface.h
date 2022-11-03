/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 31-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : EXTI_Interface.h            */
/*****************************************/

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

void EXTI_Init(void);
void EXTI0_SetCallBack(void (*fun_ptr) (void));
void EXTI1_SetCallBack(void (*fun_ptr) (void));
void EXTI2_SetCallBack(void (*fun_ptr) (void));

#endif