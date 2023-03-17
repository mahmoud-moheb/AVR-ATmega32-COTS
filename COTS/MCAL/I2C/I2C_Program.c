/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 10-1-2023     		   		 */
/*	Version: 0.1				         */
/*	File   : I2C_Program.c               */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_Private.h"
#include "I2C_Configuration.h"
#include "I2C_Interface.h"
/****************************************************************************************************************************************/

/****************************************************************************************************************************************/

/****************************************************************************************************************************************/

/****************************************************************************************************************************************/
void I2C_Init(void)
{
	I2C_ClearStatus();
	/*Set Prescaller*/
	#if Prescaler == One
		RESET_BIT(TWSR,0);
		RESET_BIT(TWSR,1);
	#elif Prescaler == Four
		SET_BIT(TWSR,0);
		RESET_BIT(TWSR,1);
	#elif Prescaler == Sixteen
		RESET_BIT(TWSR,0);
		SET_BIT(TWSR,1);
	#elif Prescaler == Sixtyfour
		SET_BIT(TWSR,0);
		SET_BIT(TWSR,1);
	#endif
	/*Set Bitrate*/
	TWBR = BitRate;
	/*Set Address*/
	TWAR = (Address<<1);
}
/****************************************************************************************************************************************/
void I2C_Write(u8 address,u8 Data)
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
		/*Load address + W into data register*/
		TWDR=address+0;
		/*Clear TWINT bit and Enable I2C*/
		TWCR = (1<<7|(1<<2));
		/*Wait until TWINT bit = 0*/
		while(((TWCR>>7)&1)==0);
		if(I2C_GetStatus()==0x18)
		{
			/*Load Data into data register*/
			TWDR=Data;
			/*Clear TWINT bit and Enable I2C*/
			TWCR = (1<<7|(1<<2));
			/*Wait until TWINT bit = 0*/
			while(((TWCR>>7)&1)==0);
			if((I2C_GetStatus()==0x28)||(I2C_GetStatus()==0x30))
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
/****************************************************************************************************************************************/
u8 I2C_Read(u8 address)
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
		/*Load address + R into data register*/
		TWDR=address+1;
		/*Clear TWINT bit and Enable I2C*/
		TWCR = (1<<7|(1<<2));
		/*Wait until TWINT bit = 0*/
		while(((TWCR>>7)&1)==0);
		if((I2C_GetStatus()==0x40)||(I2C_GetStatus()==0x48))
		{
			RESET_BIT(TWCR,6);
			/*Clear TWINT bit and Enable I2C*/
			TWCR = (1<<7|(1<<2));
			/*Wait until TWINT bit = 0*/
			while(((TWCR>>7)&1)==0);
			data=TWDR;
			if((I2C_GetStatus()==0x50)||(I2C_GetStatus()==0x58))
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
	return data;
}
/****************************************************************************************************************************************/
u8 I2C_GetStatus(void)
{
	return(TWSR & 0xF8);
}
/****************************************************************************************************************************************/
void I2C_ClearStatus(void)
{
	TWSR=(TWSR & 0x07);
}
/****************************************************************************************************************************************/
void I2C_Enable(void)
{
	SET_BIT(TWCR,2);
}
/****************************************************************************************************************************************/
void I2C_Disable(void)
{
	RESET_BIT(TWCR,2);
}
/****************************************************************************************************************************************/
void I2CInterrupt_Enable(void)
{
	SET_BIT(TWCR,0);
}
/****************************************************************************************************************************************/
void I2CInterrupt_Disable(void)
{
	RESET_BIT(TWCR,0);
}
/****************************************************************************************************************************************/
void (*I2CInterrupt_CallBack) (void);                   //create pointer to function
void I2CInterrupt_SetCallBack(void (*fun_ptr) (void))
{
	I2CInterrupt_CallBack = fun_ptr;                    //pointer created equal to pointer that refer to isr function
}
void __vector_19(void) __attribute__((signal , used));
void __vector_19(void)
{
	I2CInterrupt_CallBack();
}
/****************************************************************************************************************************************/