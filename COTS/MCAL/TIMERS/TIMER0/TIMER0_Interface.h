/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 2-11-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : TIMER0_Interface.h          */
/*****************************************/

#ifndef _TIMER0_INTERFACE_H_
#define _TIMER0_INTERFACE_H_

void TIMER0_init(void);
void PWM0(u8 duty_cycle);
void TIMER0OutputCompareMatchInterrupt_SetCallBack(void (*fun_ptr) (void));
void TIMER0OverFlowInterrupt_SetCallBack(void (*fun_ptr) (void));

#endif