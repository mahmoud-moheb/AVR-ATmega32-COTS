/*****************************************/
/*	Author : Mahmoud Moheb				 */
/*	Date   : 31-10-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : GlobalInterrupt_Program.c   */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GLOBALINTERRUPT_Private.h"
#include "GLOBALINTERRUPT_Configuration.h"
#include "GLOBALINTERRUPT_Interface.h"

void GlobalInterrupt_Init(void)
{
	#if   GlobalInterrupt == Enable
		SET_BIT(SREG,7);
	#elif GlobalInterrupt == Disable
		RESET_BIT(SREG,7);
	#endif
}

