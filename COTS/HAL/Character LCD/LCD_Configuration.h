/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 27-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : LCD_configuration.h	     */
/*****************************************/

#ifndef _LCD_CONFIGURATION_H_
#define _LCD_CONFIGURATION_H_
/*******************************/
#define LCD_Mode   FourBitsMode
/*******************************/
#define RS_DDR     DDRB
#define RS_PORT    PORTB
#define RS_PIN     PINB
#define RS_BinNum  0

#define RW_DDR     DDRB
#define RW_PORT    PORTB
#define RW_PIN     PINB
#define RW_BinNum  1

#define E_DDR      DDRB
#define E_PORT     PORTB
#define E_PIN      PINB
#define E_BinNum   2
/*******************************/
#define D0_DDR     DDRC
#define D0_PORT    PORTC
#define D0_PIN     PINC
#define D0_BinNum  0

#define D1_DDR     DDRC
#define D1_PORT    PORTC
#define D1_PIN     PINC
#define D1_BinNum  1

#define D2_DDR     DDRC
#define D2_PORT    PORTC
#define D2_PIN     PINC
#define D2_BinNum  2

#define D3_DDR     DDRC
#define D3_PORT    PORTC
#define D3_PIN     PINC
#define D3_BinNum  3

#define D4_DDR     DDRC
#define D4_PORT    PORTC
#define D4_PIN     PINC
#define D4_BinNum  4

#define D5_DDR     DDRC
#define D5_PORT    PORTC
#define D5_PIN     PINC
#define D5_BinNum  5

#define D6_DDR     DDRC
#define D6_PORT    PORTC
#define D6_PIN     PINC
#define D6_BinNum  6

#define D7_DDR     DDRC
#define D7_PORT    PORTC
#define D7_PIN     PINC
#define D7_BinNum  7
/*******************************/
#endif