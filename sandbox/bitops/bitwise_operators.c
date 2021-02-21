#include <stdio.h>

int main(void) {
    // x = 00001010
    int x = 10;
    printf("binary x: 00001010\n");
    printf("x >> 1 :: %d\n", x >> 1);
    printf("x << 1 :: %d\n", x << 1);
    printf("x << 2 :: %d\n", x << 2);
    printf("binary 40: 00101000\n");
    printf("x << 6 :: %d\n", x << 6);
    printf("binary 640: 1010000000\n");

    printf("~x :: %d\n", ~x);
    printf("binary x: 00001010\n");
    printf("binary 3: 00000011\n");
    printf("x^3 :: %d\n", x^3);
    printf("binary 9: 0001001\n");

    printf("x&3 :: %d\n", x&3);
    printf("x|3 :: %d\n", x|3);

    // People are saying that bitwise XOR is most useful opreator. 

    // Example: given a set of numbers where all elements occur even number of times except one number,
    // find the odd reccuring number
    // see reccuring.c

    // << and >> are equivilant to multiplication and division by 2, respectively

    // & can be used to check if a number is odd or even
    // x & 1 would be non-zero only if x is odd, else it would be zero

    


}