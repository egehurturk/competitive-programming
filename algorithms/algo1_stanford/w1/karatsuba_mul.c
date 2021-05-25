/*

Karatsuba's multiplication: given two n-digit integers x and y, return the product.
E.g.
if x = 5678, y = 1234,
we partition x into two pieces, namely, a and b, and y into two pieces: c and d.
a = 56, b = 78
c = 12, d = 34

We can write x and y as:

x = 10^(n/2) * a + b            (means that the half of x is going to be a, and the other half b)
y = 10^(n/2) * c + d            (means that the half of y is going to be c, and the other half d)

And the result we want to achieve is:

x * y = 10^(n) * ac + 10^(n/2) * (ad + bc) + bd

This notation, surprisingly, introduces multiplication! We are trying to solve a multiplication problem
and we have multiplication inside this problem! What a condition to let recursion into the house!
Specifically, we have 4 multiplications a*c, a*d, b*c, b*d. We will decrease this number in a moment (to reduce the time).

What's our idea? We can recursively compute ac and bd recursively and apply the same formula as well! (line 17), till we
have only 1-digit numbers left, so that we can straightforwardly calculate them in a constant time.

When we rewrite the formula again,
                        x * y = 10^(n) * ac + 10^(n/2) * (ad + bc) + bd
we see that there are 4 recursive calls, namely: ac, ad, bc, bd. We can reduce this to 3. We are only interested in
the coefficients ac, (ad + bc), and bd. To reduce the calls, we can:

1) compute a*c, b*d recursively     <x := a * c>,               <y := b * d>,
2) compute (a+b)(c+d) recursively   <z := (a+b)(c+d)>
3) compute z - y - x: (a+b)(c+d) - ac - bd

Here's the trick:

                        (a+b)(c+d) = ac + ad + bc + bd
And when we subtract ac and bd from this:
                        ac + ad + bc + bd - ac - bd = ad + bc
we will get ad + bc, which is the coefficient that we are interested in.
*/


#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int ndig(uint64_t x) {
    int counter = 0;
    do {
        counter++;
        x /= 10;
    } while (x != 0);
    return counter;
}

/* karatsuba: given two integers, multiply and return the result of the operation. */
uint64_t karatsuba(uint64_t x, uint64_t y) {


    if (x < 10 || y < 10)
        return x * y;

    // find a, b, c, d
    int n = (ndig(x) > ndig(y)) ? ndig(x) / 2 : ndig(y) / 2;
    uint64_t a = x / pow(10, n);
    uint64_t b = x % ((int) pow(10, n));
    uint64_t c = y / pow(10, n);
    uint64_t d = y % ((int) pow(10, n));

    int s1 = karatsuba(a, c);
    int s2 = karatsuba(b, d);
    int s3 = karatsuba(a+b, c+d);
    int f1 = s3 - s2 - s1;

    return pow(10, n*2)* s1 + pow(10, n) * f1 + s2;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: ./a <x> <y>\n");
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    printf("%" PRIu64 "\n", karatsuba(x, y));
}
