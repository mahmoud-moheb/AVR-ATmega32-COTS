/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 4-11-2022   		   		 */
/*	Version: 0.1				         */
/*	File   :EEPROM_Interface.h	         */
/*****************************************/


#ifndef _EEPROM_INTERFACE_H_
#define _EEPROM_INTERFACE_H_

void EEPROM_write(unsigned short int Address,unsigned char Data);
unsigned char EEPROM_read(unsigned short int Address);

#endif