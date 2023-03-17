/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 13-1-2023     		   		 */
/*	Version: 0.1				         */
/*	File   : EXTEEPROM_Program.c         */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_Private.h"
#include "I2C_Configuration.h"
#include "I2C_Interface.h"
#include "EXTEEPROM_Private.h"
#include "EXTEEPROM_Configuration.h"
#include "EXTEEPROM_Interface.h"
static u8 W_Address;
/****************************************************************************************************************************************/
void EXTEEPROM_Write(u8 Page_num,u8 Word_Address,u8 Data)
{
	/*First step  -> Clear TWINT bit
	  Second step -> Enable start condition
	  Third step  -> Enable I2C*/
	TWCR = (1<<7)|(1<<5)|(1<<2);
	/*Wait until TWINT bit = 0*/
	while(((TWCR>>7)&1)==0);
	/*Check status of start condition*/
	if(I2C_GetStatus()==0x08)
	{
		TWDR=0b10100000;
		TWDR+=(Page_num<<1);
		TWCR = (1<<7)|(1<<2);
		while(((TWCR>>7)&1)==0);
		if(I2C_GetStatus()==0x18)
		{
			TWDR=Word_Address;
			TWCR = (1<<7)|(1<<2);
		    while(((TWCR>>7)&1)==0);
			if(I2C_GetStatus()==0x28)
			{
				TWDR=Data;
				TWCR = (1<<7)|(1<<2);
				while(((TWCR>>7)&1)==0);
				if(I2C_GetStatus()==0x28)
				{
					/*First step  -> Clear TWINT bit
					  Second step -> Enable Stop condition
					  Third step  -> Enable I2C*/
					TWCR = (1<<7)|(1<<4)|(1<<2);
					/*Wait Stop condition bit to be cleared*/
					while(((TWCR>>4)&1)==1);
				}
			}
		}
	}
}
/****************************************************************************************************************************************/
u8 EXTEEPROM_ReadCurrentAddress(u8 Page_num)
{
	static u8 data;
	/*First step  -> Clear TWINT bit
	  Second step -> Enable start condition
	  Third step  -> Enable I2C*/
	TWCR = (1<<7)|(1<<5)|(1<<2);
	/*Wait until TWINT bit = 0*/
	while(((TWCR>>7)&1)==0);
	/*Check status of start condition*/
	if(I2C_GetStatus()==0x08)
	{
		TWDR=TWDR=0b10100000;
		TWDR+=(Page_num<<1)+1;
		TWCR = (1<<7)|(1<<2);
		while(((TWCR>>7)&1)==0);
		if(I2C_GetStatus()==0x40)
		{
			/*Clear TWINT bit and Enable I2C*/
			TWCR = (1<<7|(1<<2));
			/*Wait until TWINT bit = 0*/
			while(((TWCR>>7)&1)==0);
			
			if(I2C_GetStatus()==0x58)
			{
				data=TWDR;
				/*First step  -> Clear TWINT bit
				  Second step -> Enable Stop condition
				  Third step  -> Enable I2C*/
				 TWCR = (1<<7)|(1<<4)|(1<<2);
				 /*Wait Stop condition bit to be cleared*/
				 while(((TWCR>>4)&1)==1);
				 return data;
			}
		}
	}
	return '\0';
}
/****************************************************************************************************************************************/
u8 EXTEEPROM_ReadPreviousAddress(u8 Page_num)
{
	static u8 data;
	/*First step  -> Clear TWINT bit
	  Second step -> Enable start condition
	  Third step  -> Enable I2C*/
	TWCR = (1<<7)|(1<<5)|(1<<2);
	/*Wait until TWINT bit = 0*/
	while(((TWCR>>7)&1)==0);
	/*Check status of start condition*/
	if(I2C_GetStatus()==0x08)
	{
		TWDR=0b10100000;
		TWDR+=(Page_num<<1);
		TWCR = (1<<7)|(1<<2);
		while(((TWCR>>7)&1)==0);
		if(I2C_GetStatus()==0x18)
		{
			TWDR=W_Address;
			TWCR = (1<<7)|(1<<2);
		    while(((TWCR>>7)&1)==0);
			if(I2C_GetStatus()==0x28)
			{
				/*First step  -> Clear TWINT bit
				  Second step -> Enable start condition
				  Third step  -> Enable I2C*/
				TWCR = (1<<7)|(1<<5)|(1<<2);
				/*Wait until TWINT bit = 0*/
				while(((TWCR>>7)&1)==0);
				/*Check status of Repeated start condition*/
				if(I2C_GetStatus()==0x10)
				{
					TWDR=TWDR=0b10100000;
					TWDR+=(Page_num<<1)+1;
					TWCR = (1<<7)|(1<<2);
					while(((TWCR>>7)&1)==0);
					if(I2C_GetStatus()==0x40)
					{
						/*Clear TWINT bit and Enable I2C*/
						TWCR = (1<<7)|(1<<2);
						/*Wait until TWINT bit = 0*/
						while(((TWCR>>7)&1)==0);
						if(I2C_GetStatus()==0x58)
						{
							data=TWDR;
							/*First step  -> Clear TWINT bit
							  Second step -> Enable Stop condition
							  Third step  -> Enable I2C*/
							TWCR = (1<<7)|(1<<4)|(1<<2);
							/*Wait Stop condition bit to be cleared*/
							while(((TWCR>>4)&1)==1);
							return data;
						}
					}
				}
			}
		}
	}
	return '\0';
}
/****************************************************************************************************************************************/
u8 EXTEEPROM_ReadSpecificAddress(u8 Page_num,u8 Word_Address)
{
	static u8 data;
	W_Address=Word_Address;
	/*First step  -> Clear TWINT bit
	  Second step -> Enable start condition
	  Third step  -> Enable I2C*/
	TWCR = (1<<7)|(1<<5)|(1<<2);
	/*Wait until TWINT bit = 0*/
	while(((TWCR>>7)&1)==0);
	/*Check status of start condition*/
	if(I2C_GetStatus()==0x08)
	{
		TWDR=0b10100000;
		TWDR+=(Page_num<<1);
		TWCR = (1<<7)|(1<<2);
		while(((TWCR>>7)&1)==0);
		if(I2C_GetStatus()==0x18)
		{
			TWDR=Word_Address;
			TWCR = (1<<7)|(1<<2);
		    while(((TWCR>>7)&1)==0);
			if(I2C_GetStatus()==0x28)
			{
				/*First step  -> Clear TWINT bit
				  Second step -> Enable start condition
				  Third step  -> Enable I2C*/
				TWCR = (1<<7)|(1<<5)|(1<<2);
				/*Wait until TWINT bit = 0*/
				while(((TWCR>>7)&1)==0);
				/*Check status of Repeated start condition*/
				if(I2C_GetStatus()==0x10)
				{
					TWDR=TWDR=0b10100000;
					TWDR+=(Page_num<<1)+1;
					TWCR = (1<<7)|(1<<2);
					while(((TWCR>>7)&1)==0);
					if(I2C_GetStatus()==0x40)
					{
						/*Clear TWINT bit and Enable I2C*/
						TWCR = (1<<7)|(1<<2);
						/*Wait until TWINT bit = 0*/
						while(((TWCR>>7)&1)==0);
						if(I2C_GetStatus()==0x58)
						{
							data=TWDR;
							/*First step  -> Clear TWINT bit
							  Second step -> Enable Stop condition
							  Third step  -> Enable I2C*/
							TWCR = (1<<7)|(1<<4)|(1<<2);
							/*Wait Stop condition bit to be cleared*/
							while(((TWCR>>4)&1)==1);
							return data;
						}
					}
				}
			}
		}
	}
	return '\0';
}
/****************************************************************************************************************************************/