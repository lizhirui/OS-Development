#include "common.h"
#include "string.h"

uint String_GetLen(uchar *str)
{
	uint i;
	
	i = 0;
	
	while((*str) != STRING_STR_END)
	{
		str++;
		i++;
	}
	
	return i;
}