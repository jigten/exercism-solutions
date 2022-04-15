#include "binary_search.h"

int *binary_search(int value, const int *arr, size_t length)
{
	size_t l = 0, r = length;
	while (l < r)
	{
		size_t mid = l + (r - l) / 2;
		int mid_value = arr[mid];
		
		if (mid_value == value)
		{
			return (int *) &arr[mid];
		}

		if (mid_value > value)
		{
			r = mid;
		}

		if (mid_value < value)
		{
			l = mid + 1;
		}
	}

	return NULL;
}
