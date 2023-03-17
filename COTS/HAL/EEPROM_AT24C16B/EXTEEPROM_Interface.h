/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 13-1-2023     		   		 */
/*	Version: 0.1				         */
/*	File   : EXTEEPROM_Interface.h       */
/*****************************************/

#ifndef _EXTEEPROM_INTERFACE_H_
#define _EXTEEPROM_INTERFACE_H_

void EXTEEPROM_Write(u8,u8,u8);
u8 EXTEEPROM_ReadCurrentAddress(u8);
u8 EXTEEPROM_ReadPreviousAddress(u8);
u8 EXTEEPROM_ReadSpecificAddress(u8,u8);

#endif