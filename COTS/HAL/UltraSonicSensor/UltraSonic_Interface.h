/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 25-2-2023  		   		 */
/*	Version: 0.1				         */
/*	File   : UltraSonic_interface.h	     */
/*****************************************/

#ifndef _ULTRASONIC_INTERFACE_H_
#define _ULTRASONIC_INTERFACE_H_

void UltraSonic_Init(void);
f32 UltraSonic_GetDistance(void);
void InputCaptureInterruptHandler(void);

#endif