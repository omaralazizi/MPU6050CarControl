#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "GIE_config.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_register.h"


void GIE_Enable(void)
{
	
	SET_BIT(SREG,7);
	
}
void GIE_Disable(void)
{
	
	CLR_BIT(SREG,7);
	
}

