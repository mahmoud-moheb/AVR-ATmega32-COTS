/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 25-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : BIT_MATH.h	                 */
/*****************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(reg_name,bit_num)       reg_name|=(1<<bit_num)
#define RESET_BIT(reg_name,bit_num)     reg_name&=~(1<<bit_num)
#define TOGGLE_BIT(reg_name,bit_num)    reg_name^=(1<<bit_num)
#define GET_BITVAL(reg_name,bit_num)    (reg_name>>bit_num)&1
#define CIRCULAR_SHIFTL(reg_name,shift) (reg_name<<shift)|(reg_name>>(8-shift))
#define CIRCULAR_SHIFTR(reg_name,shift) (reg_name>>shift)|(reg_name<<(8-shift))

#endif