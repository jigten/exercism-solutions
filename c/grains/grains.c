#include "grains.h"
#include <stdio.h>

uint64_t square(uint8_t index)
{
	if (index > 64 || index <= 0) return 0;
	uint64_t grains = 1;
	grains <<= (index - 1);
	return grains;
}

uint64_t total(void)
{
	return 18446744073709551615ull;  
}

