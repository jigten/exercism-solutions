#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate)
{
    double sum = 0;
    int digit;
    int n = log10(candidate) + 1;
    int candidateCopy = candidate;

    while (candidateCopy)
    {
        digit = candidateCopy % 10;
        int temp_total = 1;
        for (int i = 0; i < n; i++)
            temp_total *= digit;
        sum += temp_total;
        candidateCopy /= 10;
    }
    return (int)sum == candidate;
}
