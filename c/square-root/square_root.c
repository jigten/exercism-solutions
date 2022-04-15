#include "square_root.h"
#include <stdlib.h>

int improve_guess(int radicand, int guess)
{
	return (guess + radicand / guess) / 2;
}

bool close_enough(int radicand, int guess)
{
	return abs(radicand - (guess * guess)) <= 0.0001;
}

int sqrt_iter(int radicand, int guess)
{
	if (close_enough(radicand, guess))
	{
		return guess;
	}
	return sqrt_iter(radicand, improve_guess(radicand, guess));
}

int square_root(int radicand)
{	
	return sqrt_iter(radicand, 1);
}
