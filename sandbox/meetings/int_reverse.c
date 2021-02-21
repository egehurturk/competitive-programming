#include <stdio.h>

int digitNo(int x);
int rightMostValue(int z);
int reverseNumber(int y);
int reverseT(int y);
int main(void) {    
    int n;
    scanf("%d", &n);
    printf("%d\n", reverseNumber(n));
    printf("%d\n", reverseT(n));
}

int digitNo(int x) {
    int digitNo = 0;
    while (x > 10) {digitNo++; x/=10;}
    return digitNo;
}

int rightMostValue(int z) {
    return z % 10;

    // OR
    // no = z / 10;
    // return z - (no * 10);

}

int reverseNumber(int number) { // 273923
    int reverse = 0, counter = 1;
    int digitNumOfNumber = digitNo(number);
    int tenthPow = 1;
    // 6
    while (counter < digitNumOfNumber) {
        counter += 1;
        tenthPow *= 10;
    }
    // 1000000
    
    counter = 0;
    while (counter < digitNumOfNumber) {
        reverse += rightMostValue(number) * tenthPow; // reverse'ü oluştur
        number /= 10; // En sağdaki değeri sil
        tenthPow /= 10; // 10'un kuvvetini bir azalt
        counter += 1; // Counter'ı bir arttır
    }
    
    return reverse;
}

int reverseT(int y) {
    int rev = 0, rem;

    while (y != 0) {
        rem = y % 10;
        rev = rev * 10 + rem;
        y /= 10;
    }
    return rev;
}