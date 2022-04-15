#ifndef SQUARE_ROOT_H
#define SQUARE_ROOT_H
#include <stdbool.h>
int improve_guess(int radicand, int guess);
bool close_enough(int radicand, int guess);
int sqrt_iter(int radicand, int guess);
int square_root(int radicand);
#endif
