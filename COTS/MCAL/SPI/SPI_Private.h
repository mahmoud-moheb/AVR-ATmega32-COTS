/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 9-1-2023   		   		 */
/*	Version: 0.1				         */
/*	File   : SPI_Private.h	             */
/*****************************************/

#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_

#define SPCR  	*((volatile u8*)0x2D)
#define SPSR 	*((volatile u8*)0x2E)
#define SPDR    *((volatile u8*)0x2F)
/*Data Order*/
#define MSBTransFirst 							0
#define LSBTransFirst                   		1
/*Masster Slave Select*/
#define Master                          		1
#define Slave                           		0
/*Clock Polarity*/
#define LeadingEdgeRisingTrailingEdgeFalling    0
#define	LeadingEdgeFallingTrailingEdgeRising    1
/*Clock Phase*/
#define LeadingEdgeSampleTrailingEdgeSetup      0
#define	LeadingEdgeSetupTrailingEdgeSample      1
/*Clock Rate*/
#define FoscDiv4                                0
#define FoscDiv16                               1
#define FoscDiv64                               2
#define FoscDiv128                              3
#define FoscDiv2                                4
#define FoscDiv8                                5
#define FoscDiv32                               6
#define FoscDiv_64                              7
                  
#endif

