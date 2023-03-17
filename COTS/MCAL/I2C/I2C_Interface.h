/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 10-1-2023     		   		 */
/*	Version: 0.1				         */
/*	File   : I2C_Interface.h             */
/*****************************************/

#ifndef _I2C_INTERFACE_H_
#define _I2C_INTERFACE_H_

void I2C_Init(void);
void I2C_Write(u8,u8);
u8 I2C_Read(u8);
u8 I2C_GetStatus(void);
void I2C_ClearStatus(void);
void I2C_Enable(void);
void I2C_Disable(void);
void I2CInterrupt_Enable(void);
void I2CInterrupt_Disable(void);
void I2CInterrupt_SetCallBack(void (*fun_ptr) (void));

#endif