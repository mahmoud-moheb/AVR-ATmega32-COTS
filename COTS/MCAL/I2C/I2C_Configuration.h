/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 10-1-2023     		   		 */
/*	Version: 0.1				         */
/*	File   : I2C_Configuration.h         */
/*****************************************/
#ifndef _I2C_CONFIGURATION_H_
#define _I2C_CONFIGURATION_H_


#define MasterFreuency      8000000UL 
#define SlaveFreuency 	    400000UL
#define Prescaler           One 
#define BitRate             (((MasterFreuency/SlaveFreuency)-16)/(2*Prescaler))
#define Address             0x20
                      
#endif