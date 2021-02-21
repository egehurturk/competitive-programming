#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; // lower limit of temperature
    upper = 300;
    step = 20;

    fahr = lower; 
    printf("\n\n\n");
    printf("\t\t============ Fahrenheit to Celsius ============\t\t\n");
    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr - 32);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step;
    }
}