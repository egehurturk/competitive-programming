#include <stdio.h>

float power(int base, int power) {
    float result = 1;
    for (int i = 0; i < power; i++) {
        result *= base;
    }
    return result;
}

int armstrong(int num) {
    int originalNum = num, remainder, n = 0;
    float result = 0.0;

    // get number of digits
    while (originalNum != 0) {
        n++;
        originalNum /= 10;
    }
    originalNum = num;
    // calculate 
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += power(remainder, n);
        originalNum /= 10;
    }
    return result;
}

int main() {
    int num;
    scanf("%d", &num);
    int result = armstrong(num);
    if ((int)result == num)
        printf("Evet\n");
    else
        printf("Hayır\n");
    return 0;
}