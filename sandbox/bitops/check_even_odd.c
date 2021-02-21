#include <stdio.h>

int main(void) 
{
    int x = 19;
    // If x&1 is 0, then it is even. Else, it is odd
    (x & 1) ? printf("Odd") : printf("Even");
}

// Conclusion 1: X & 1 will make every bits zero excluding the first-value. E.g:
// 00010010 & 00000001 = 00000000 (EVEN)
// 00010011 & 00000001 = 00000001 (ODD)