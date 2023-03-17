/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 27-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : LCD_interface.h	         */
/*****************************************/

#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

void LCD_Init(void);
void LCD_DisplayChar(u8 Character);
void LCD_DisplayString(u8 String[]);
void LCD_ON(void);
void LCD_OFF(void);
void LCD_CursorON(void);
void LCD_CursorOFF(void);
void LCD_SetCursorPosition(u16 row,u16 col);
void LCD_Clear(void);

#endif