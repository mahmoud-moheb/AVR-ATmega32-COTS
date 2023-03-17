/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 9-1-2023     		   		 */
/*	Version: 0.1				         */
/*	File   : SPI_Interface.h             */
/*****************************************/

#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_

void SPIMaster_Init(void);
void SPISlave_Init(void);
void SPI_Enable(void);
void SPI_Disable(void);
void SPIMaster_Send(u8);
u8 SPIMaster_Receive(void);
void SPISlave_Send(u8);
u8 SPISlave_Receive(void);
void SPITransferCompleteInterrupt_Enable(void);
void SPITransferCompleteInterrupt_Disable(void);
void SPITransferCompleteInterrupt_SetCallBack(void (*fun_ptr) (void));

#endif