/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 31-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : ADC_Private.h	             */
/*****************************************/

#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

#define ADMUX  *((volatile u8*)0x27)
#define ADCSRA *((volatile u8*)0x26)
#define ADCH   *((volatile u8*)0x25)
#define ADCL   *((volatile u8*)0x24)
#define SFIOR  *((volatile u8*)0x50)


#define AREF          0 
#define AVCC          1 
#define Internal_VREF 3 
#define LeftAdjust    1 
#define RightAdjust   0

#endif

