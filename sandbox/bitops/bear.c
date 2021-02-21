#include <stdio.h>

int main(void)
{
    int a,b,n=0;
    scanf("%i", &a);
    scanf("%i", &b);
    while (a<=b)
    {       
        a*=3;
        b*=2;
        n++;
    }
    printf("%d\n", n);

}