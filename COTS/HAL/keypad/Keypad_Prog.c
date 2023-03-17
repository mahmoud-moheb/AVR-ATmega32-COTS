/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 26-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : KeyPad_Prog.c		         */
/*****************************************/

#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "Keypad_Private.h"
#include "Keypad_Configuration.h"
#include "Keypad_Interface.h"
void Keypad_Init(void)
{
 SET_BIT(ROW0_DDR,ROW0_BIN);
 SET_BIT(ROW1_DDR,ROW1_BIN);
 SET_BIT(ROW2_DDR,ROW2_BIN);
 SET_BIT(ROW3_DDR,ROW3_BIN);
 RESET_BIT(COL0_DDR,COL0_BIN);
 RESET_BIT(COL1_DDR,COL1_BIN);
 RESET_BIT(COL2_DDR,COL0_BIN);
 RESET_BIT(COL3_DDR,COL3_BIN);
 SET_BIT(COL0_PORT,COL0_BIN);
 SET_BIT(COL1_PORT,COL1_BIN);
 SET_BIT(COL2_PORT,COL2_BIN);
 SET_BIT(COL3_PORT,COL3_BIN);
}
char Get_BressedButton(void)
{
	RESET_BIT(ROW0_PORT,ROW0_BIN);
	SET_BIT(ROW1_PORT,ROW1_BIN);
	SET_BIT(ROW2_PORT,ROW2_BIN);
	SET_BIT(ROW3_PORT,ROW3_BIN);
	_delay_ms(5);
	if(GET_BITVAL(COL0_PORT,COL0_BIN)==0)
	{
		return '1';
		while(GET_BITVAL(COL0_PORT,COL0_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL1_PORT,COL1_BIN)==0)
	{
		return '2';
		while(GET_BITVAL(COL1_PORT,COL1_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL2_PORT,COL2_BIN)==0)
	{
		return '3';
		while(GET_BITVAL(COL2_PORT,COL2_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL3_PORT,COL3_BIN)==0)
	{
		return 'A';
		while(GET_BITVAL(COL3_PORT,COL3_BIN)==0)
		{
			
		}
	}
	SET_BIT(ROW0_PORT,ROW0_BIN);
	RESET_BIT(ROW1_PORT,ROW1_BIN);
	SET_BIT(ROW2_PORT,ROW2_BIN);
	SET_BIT(ROW3_PORT,ROW3_BIN);
	_delay_ms(5);
	if(GET_BITVAL(COL0_PORT,COL0_BIN)==0)
	{
		return '4';
		while(GET_BITVAL(COL0_PORT,COL0_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL1_PORT,COL1_BIN)==0)
	{
		return '5';
		while(GET_BITVAL(COL1_PORT,COL1_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL2_PORT,COL2_BIN)==0)
	{
		return '6';
		while(GET_BITVAL(COL2_PORT,COL2_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL3_PORT,COL3_BIN)==0)
	{
		return 'B';
		while(GET_BITVAL(COL3_PORT,COL3_BIN)==0)
		{
			
		}
	}
	SET_BIT(ROW0_PORT,ROW0_BIN);
	SET_BIT(ROW1_PORT,ROW1_BIN);
	RESET_BIT(ROW2_PORT,ROW2_BIN);
	SET_BIT(ROW3_PORT,ROW3_BIN);
	_delay_ms(5);
	if(GET_BITVAL(COL0_PORT,COL0_BIN)==0)
	{
		return '7';
		while(GET_BITVAL(COL0_PORT,COL0_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL1_PORT,COL1_BIN)==0)
	{
		return '8';
		while(GET_BITVAL(COL1_PORT,COL1_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL2_PORT,COL2_BIN)==0)
	{
		return '9';
		while(GET_BITVAL(COL2_PORT,COL2_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL3_PORT,COL3_BIN)==0)
	{
		return 'C';
		while(GET_BITVAL(COL3_PORT,COL3_BIN)==0)
		{
			
		}
	}
	SET_BIT(ROW0_PORT,ROW0_BIN);
	SET_BIT(ROW1_PORT,ROW1_BIN);
	SET_BIT(ROW2_PORT,ROW2_BIN);
	RESET_BIT(ROW3_PORT,ROW3_BIN);
	_delay_ms(5);
	if(GET_BITVAL(COL0_PORT,COL0_BIN)==0)
	{
		return '*';
		while(GET_BITVAL(COL0_PORT,COL0_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL1_PORT,COL1_BIN)==0)
	{
		return '0';
		while(GET_BITVAL(COL1_PORT,COL1_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL2_PORT,COL2_BIN)==0)
	{
		return '#';
		while(GET_BITVAL(COL2_PORT,COL2_BIN)==0)
		{
			
		}
	}
	else if(GET_BITVAL(COL3_PORT,COL3_BIN)==0)
	{
		return 'D';
		while(GET_BITVAL(COL3_PORT,COL3_BIN)==0)
		{
			
		}
	}
}