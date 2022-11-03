/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 30-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : 7Segments_Prog.c		     */
/*****************************************/

#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "7Segments_Private.h"
#include "7Segments_Configuration.h"
#include "7Segments_Interface.h"
#if SegmentsMode == CommonCathode7
	u8 N[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111100,0b00000111,0b01111111,0b01100111};
	void Display_Num(u8 Num)
	{
		if(GET_BITVAL(N[Num],0)==1)
		{
			SET_BIT(a_PORT,a_BinNum);
		}
		else
		{
			RESET_BIT(a_PORT,a_BinNum);
		}
		if(GET_BITVAL(N[Num],1)==1)
		{
			SET_BIT(b_PORT,b_BinNum);
		}
		else
		{
			RESET_BIT(b_PORT,b_BinNum);
		}
		if(GET_BITVAL(N[Num],2)==1)
		{
			SET_BIT(c_PORT,c_BinNum);
		}
		else
		{
			RESET_BIT(c_PORT,c_BinNum);
		}
		if(GET_BITVAL(N[Num],3)==1)
		{
			SET_BIT(d_PORT,d_BinNum);
		}
		else
		{
			RESET_BIT(d_PORT,d_BinNum);
		}
		if(GET_BITVAL(N[Num],4)==1)
		{
			SET_BIT(e_PORT,e_BinNum);
		}
		else
		{
			RESET_BIT(e_PORT,e_BinNum);
		}
		if(GET_BITVAL(N[Num],5)==1)
		{
			SET_BIT(f_PORT,f_BinNum);
		}
		else
		{
			RESET_BIT(f_PORT,f_BinNum);
		}
		if(GET_BITVAL(N[Num],6)==1)
		{
			SET_BIT(g_PORT,g_BinNum);
		}
		else
		{
			RESET_BIT(g_PORT,g_BinNum);
		}
	}
#elif SegmentsMode == CommonAnode7
	u8 N[10]={0b01000000,0b01111001,0b00100100,0b00110000,0b00011001,0b00010010,0b00000011,0b01111000,0b00000000,0b00011000};
	void Display_Num(u8 Num)
	{
		if(GET_BITVAL(N[Num],0)==1)
		{
			SET_BIT(a_PORT,a_BinNum);
		}
		else
		{
			RESET_BIT(a_PORT,a_BinNum);
		}
		if(GET_BITVAL(N[Num],1)==1)
		{
			SET_BIT(b_PORT,b_BinNum);
		}
		else
		{
			RESET_BIT(b_PORT,b_BinNum);
		}
		if(GET_BITVAL(N[Num],2)==1)
		{
			SET_BIT(c_PORT,c_BinNum);
		}
		else
		{
			RESET_BIT(c_PORT,c_BinNum);
		}
		if(GET_BITVAL(N[Num],3)==1)
		{
			SET_BIT(d_PORT,d_BinNum);
		}
		else
		{
			RESET_BIT(d_PORT,d_BinNum);
		}
		if(GET_BITVAL(N[Num],4)==1)
		{
			SET_BIT(e_PORT,e_BinNum);
		}
		else
		{
			RESET_BIT(e_PORT,e_BinNum);
		}
		if(GET_BITVAL(N[Num],5)==1)
		{
			SET_BIT(f_PORT,f_BinNum);
		}
		else
		{
			RESET_BIT(f_PORT,f_BinNum);
		}
		if(GET_BITVAL(N[Num],6)==1)
		{
			SET_BIT(g_PORT,g_BinNum);
		}
		else
		{
			RESET_BIT(g_PORT,g_BinNum);
		}
	}
#elif SegmentsMode == BCDto7Segments
	u8 N[10]={0b00000000,0b00000001,0b00000010,0b00000011,0b00000100,0b00000101,0b00000110,0b00000111,0b00001000,0b00001001};
	void Display_Num(u8 Num)
	{
		if(GET_BITVAL(N[Num],0)==1)
		{
			SET_BIT(A_PORT,A_BinNum);
		}
		else
		{
			RESET_BIT(A_PORT,A_BinNum);
		}
		if(GET_BITVAL(N[Num],1)==1)
		{
			SET_BIT(B_PORT,B_BinNum);
		}
		else
		{
			RESET_BIT(B_PORT,B_BinNum);
		}
		if(GET_BITVAL(N[Num],2)==1)
		{
			SET_BIT(C_PORT,C_BinNum);
		}
		else
		{
			RESET_BIT(C_PORT,C_BinNum);
		}
		if(GET_BITVAL(N[Num],3)==1)
		{
			SET_BIT(D_PORT,D_BinNum);
		}
		else
		{
			RESET_BIT(D_PORT,D_BinNum);
		}
	}
#endif
