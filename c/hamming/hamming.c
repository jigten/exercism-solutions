#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
	int distance = 0;
	while (*lhs && *rhs)
	{
		if (*lhs != *rhs)
		{
			distance += 1;
		}
		lhs++;
		rhs++;
	}
	if (*lhs || *rhs)
	{
		return -1;
	}

	return distance;
}

