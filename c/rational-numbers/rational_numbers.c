#include "rational_numbers.h"
#include <math.h>

static int gcd(int x, int y) {
    if (y == 0 && x < 0) return -x;
    if (y == 0) return x;
    return gcd(y, x%y);
}

static int fast_exp(int base, int power) {
    int result = 1;
    while (power > 0) {
        if (power % 2 != 0) {
            power = power - 1;
            result = result * base; 
        }
        power = power / 2;
        base = base * base;
    }
    return result;
}

static rational_t negative(rational_t r) {
    rational_t neg = {-r.numerator, r.denominator};
    return neg;
}

static rational_t inverse(rational_t r) {
    rational_t inv = {r.denominator, r.numerator};
    return inv;
}

rational_t add(rational_t r1, rational_t r2) {
    int a1 = r1.numerator; 
    int b1 = r1.denominator;  
    int a2 = r2.numerator;
    int b2 = r2.denominator;
    rational_t ans = {a1 * b2 + a2 * b1, b1 * b2};
    return reduce(ans);
}

rational_t subtract(rational_t r1, rational_t r2) {
    return add(r1, negative(r2));
}

rational_t multiply(rational_t r1, rational_t r2) {
    int a1 = r1.numerator; 
    int b1 = r1.denominator;  
    int a2 = r2.numerator;
    int b2 = r2.denominator;
    rational_t ans = {a1 * a2, b1 * b2};
    return reduce(ans);
}

rational_t divide(rational_t r1, rational_t r2) {
    return multiply(r1, inverse(r2));
}

rational_t absolute(rational_t r) {
    int a1 = r.numerator;
    int b1 = r.denominator; 
    rational_t ans = {a1 >= 0 ? a1 : -a1, b1 >= 0 ? b1 : -b1};
    return ans;
}

rational_t exp_rational(rational_t r, int n) {
    int a1 = r.numerator;
    int b1 = r.denominator;
    if (n < 0) {
        int m = -n;
        rational_t ans = {fast_exp(b1, m), fast_exp(a1, m)};
        return ans;
    }    
    rational_t ans = {fast_exp(a1, n), fast_exp(b1, n)};
    return ans;
}

float exp_real(int x, rational_t r) {
    return pow(x, (double)((double)r.numerator/(double)r.denominator));
}

rational_t reduce(rational_t r) {
    int a1 = r.numerator;
    int b1 = r.denominator;
    int z = gcd(a1, b1);
    int num = a1 / z;
    int denom = b1 / z;
    if (denom < 0) {
        num = -num;
        denom = -denom;
    }
    rational_t ans = {num, denom};
    return ans;
}

