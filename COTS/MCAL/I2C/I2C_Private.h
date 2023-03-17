/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 10-1-2023   		   		 */
/*	Version: 0.1				         */
/*	File   : I2C_Private.h	             */
/*****************************************/

#ifndef _I2C_PRIVATE_H_
#define _I2C_PRIVATE_H_

#define TWBR *((volatile u8*)0x20)
#define TWCR *((volatile u8*)0x56)
#define TWSR *((volatile u8*)0x21)
#define TWDR *((volatile u8*)0x23)
#define TWAR *((volatile u8*)0x22)

/*Prescaler Values*/
#define One              1
#define Four             4
#define Sixteen          16
#define Sixtyfour        64

#endif

