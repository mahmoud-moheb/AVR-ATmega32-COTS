/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 25-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : DIO_Program.c               */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_Configuration.h"
void DIO_Init(void)
{
#if DDRA0 == OUTPUT
	SET_BIT(DDRA,0);
#else
	RESET_BIT(DDRA,0);
#endif
#if DDRA1 == OUTPUT
	SET_BIT(DDRA,1);
#else
	RESET_BIT(DDRA,1);
#endif
#if DDRA2 == OUTPUT
	SET_BIT(DDRA,2);
#else
	RESET_BIT(DDRA,2);
#endif
#if DDRA3 == OUTPUT
	SET_BIT(DDRA,3);
#else
	RESET_BIT(DDRA,3);
#endif
#if DDRA4 == OUTPUT
	SET_BIT(DDRA,4);
#else
	RESET_BIT(DDRA,4);
#endif
#if DDRA5 == OUTPUT
	SET_BIT(DDRA,5);
#else
	RESET_BIT(DDRA,5);
#endif
#if DDRA6 == OUTPUT
	SET_BIT(DDRA,6);
#else
	RESET_BIT(DDRA,6);
#endif
#if DDRA7 == OUTPUT
	SET_BIT(DDRA,7);
#else
	RESET_BIT(DDRA,7);
#endif
/******************/
#if DDRB0 == OUTPUT
	SET_BIT(DDRB,0);
#else
	RESET_BIT(DDRB,0);
#endif
#if DDRB1 == OUTPUT
	SET_BIT(DDRB,1);
#else
	RESET_BIT(DDRB,1);
#endif
#if DDRB2 == OUTPUT
	SET_BIT(DDRB,2);
#else
	RESET_BIT(DDRB,2);
#endif
#if DDRB3 == OUTPUT
	SET_BIT(DDRB,3);
#else
	RESET_BIT(DDRB,3);
#endif
#if DDRB4 == OUTPUT
	SET_BIT(DDRB,4);
#else
	RESET_BIT(DDRB,4);
#endif
#if DDRB5 == OUTPUT
	SET_BIT(DDRB,5);
#else
	RESET_BIT(DDRB,5);
#endif
#if DDRB6 == OUTPUT
	SET_BIT(DDRB,6);
#else
	RESET_BIT(DDRB,6);
#endif
#if DDRB7 == OUTPUT
	SET_BIT(DDRB,7);
#else
	RESET_BIT(DDRB,7);
#endif
/******************/
#if DDRC0 == OUTPUT
	SET_BIT(DDRC,0);
#else
	RESET_BIT(DDRC,0);
#endif
#if DDRC1 == OUTPUT
	SET_BIT(DDRC,1);
#else
	RESET_BIT(DDRC,1);
#endif
#if DDRC2 == OUTPUT
	SET_BIT(DDRC,2);
#else
	RESET_BIT(DDRC,2);
#endif
#if DDRC3 == OUTPUT
	SET_BIT(DDRC,3);
#else
	RESET_BIT(DDRC,3);
#endif
#if DDRC4 == OUTPUT
	SET_BIT(DDRC,4);
#else
	RESET_BIT(DDRC,4);
#endif
#if DDRC5 == OUTPUT
	SET_BIT(DDRC,5);
#else
	RESET_BIT(DDRC,5);
#endif
#if DDRC6 == OUTPUT
	SET_BIT(DDRC,6);
#else
	RESET_BIT(DDRC,6);
#endif
#if DDRC7 == OUTPUT
	SET_BIT(DDRC,7);
#else
	RESET_BIT(DDRC,7);
#endif
/******************/
#if DDRD0 == OUTPUT
	SET_BIT(DDRD,0);
#else
	RESET_BIT(DDRD,0);
#endif
#if DDRD1 == OUTPUT
	SET_BIT(DDRD,1);
#else
	RESET_BIT(DDRD,1);
#endif
#if DDRD2 == OUTPUT
	SET_BIT(DDRD,2);
#else
	RESET_BIT(DDRD,2);
#endif
#if DDRD3 == OUTPUT
	SET_BIT(DDRD,3);
#else
	RESET_BIT(DDRD,3);
#endif
#if DDRD4 == OUTPUT
	SET_BIT(DDRD,4);
#else
	RESET_BIT(DDRD,4);
#endif
#if DDRD5 == OUTPUT
	SET_BIT(DDRD,5);
#else
	RESET_BIT(DDRD,5);
#endif
#if DDRD6 == OUTPUT
	SET_BIT(DDRD,6);
#else
	RESET_BIT(DDRD,6);
#endif
#if DDRD7 == OUTPUT
	SET_BIT(DDRD,7);
#else
	RESET_BIT(DDRD,7);
#endif
/******************/
}
void Set_Bit(volatile u8* port,u8 pin_num)
{
	*port|=(1<<pin_num);
}
void Reset_Bit(volatile u8* port,u8 pin_num)
{
	*port&=~(1<<pin_num);
}
void Toggle_Bit(volatile u8* port,u8 pin_num)
{
	*port^=(1<<pin_num);
}