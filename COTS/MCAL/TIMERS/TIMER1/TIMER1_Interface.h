/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 6-11-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : TIMER1_Interface.h          */
/*****************************************/

#ifndef _TIMER1_INTERFACE_H_
#define _TIMER1_INTERFACE_H_

void TIMER1_init(void);
void TIMER1_Stop(void);
void TIMER1_Start(u16 prescaler);
void Timer1OverFlowInterrupt_Enable(void);
void Timer1OverFlowInterrupt_Disable(void);
void Timer1AOutputCompareMatchInterrupt_Enable(void);
void Timer1AOutputCompareMatchInterrupt_Disable(void);
void Timer1BOutputCompareMatchInterrupt_Enable(void);
void Timer1BOutputCompareMatchInterrupt_Disable(void);
void Timer1InputCaptureInterrupt_Enable(void);
void Timer1InputCaptureInterrupt_Disable(void);
void PWM1A(u8 duty_cycle);
void PWM1B(u8 duty_cycle);
void TIMER1OverFlowInterrupt_SetCallBack(void (*fun_ptr) (void));
void TIMER1AOutputCompareMatchInterrupt_SetCallBack(void (*fun_ptr) (void));
void TIMER1BOutputCompareMatchInterrupt_SetCallBack(void (*fun_ptr) (void));
void Timer1InputCaptureInterrupt_SetCallBack(void (*fun_ptr) (void));

#endif