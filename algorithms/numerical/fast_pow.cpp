#include <bits/stdc++.h>

using namespace std;

int exp_slow(int base, int exp);
int exp(int base, int exp);

int main(void) {
    printf("5^6 = %d\n", exp_slow(5, 6));
    printf("5^6 = %d\n", exp(5, 6));
}

int exp(int base, int exp) {
    int res = 1;

    while (exp) {
        if (exp % 2 == 1)
            res *= base;
        exp >>= 1;
        base = (base * base);
    }
    return res;
}

int exp_slow(int base, int exp) {
    int prod = 1;
    for (int i = 0; i < exp; i++)
        prod *= base;
    return prod;
}



/*

FAST EXPONENTIATION (MODULAR EXPONENTIATION):
---------------------------------------------

Problem statement
Input: three integers x, y, p
Output: (x^y) mod p



if we need to calculate 2^6, we could break it into
2^3 * 2^3. We can then break 2^3 as 2*2^1*2^1. We 
can then break 2^1 as 2*2^0 * 2^0.

2^6 = 2^3 * 2^3
2^3 = 2 * 2^1 * 2^1
2^1 = 2 * 2^0 * 2^0

power(x, y) {
    if (y == 0)
        return 1;
    temp = power(x, y/2)
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}


call stack:


pow(2, 0) --> 1
pow(2, 1) --> 2
pow(2, 2) --> 4
pow(2, 5) --> 2 * 16 = 32




*/


