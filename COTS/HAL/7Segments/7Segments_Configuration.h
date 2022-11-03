/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 30-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : 7Segments_Configuration.h   */
/*****************************************/

#ifndef _7SEGMENTS_CONFIGURATION_H_
#define _7SEGMENTS_CONFIGURATION_H_

#define SegmentsMode BCDto7Segments
#if SegmentsMode == CommonCathode7
	#define a_PORT            PORTC
	#define a_BinNum          0
	#define b_PORT            PORTC
	#define b_BinNum          1
	#define c_PORT            PORTC
	#define c_BinNum          2
	#define d_PORT            PORTC
	#define d_BinNum          3
	#define e_PORT            PORTC
	#define e_BinNum          4
	#define f_PORT            PORTC
	#define f_BinNum          5
	#define g_PORT            PORTC
	#define g_BinNum          6
#elif SegmentsMode == CommonAnode7
	#define a_PORT            PORTC
	#define a_BinNum          0
	#define b_PORT            PORTC
	#define b_BinNum          1
	#define c_PORT            PORTC
	#define c_BinNum          2
	#define d_PORT            PORTC
	#define d_BinNum          3
	#define e_PORT            PORTC
	#define e_BinNum          4
	#define f_PORT            PORTC
	#define f_BinNum          5
	#define g_PORT            PORTC
	#define g_BinNum          6
#elif SegmentsMode == BCDto7Segments
	#define A_PORT            PORTC
	#define A_BinNum          0
	#define B_PORT            PORTC
	#define B_BinNum          1
	#define C_PORT            PORTC
	#define C_BinNum          2
	#define D_PORT            PORTC
	#define D_BinNum          3
#endif

#endif