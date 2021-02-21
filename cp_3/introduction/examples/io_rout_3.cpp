#include <iostream>

int main(void)
{
    int a,b;

    while (scanf("%d %d", &a, &b), (a || b)) // a || b for if both are 0
        printf("%d\n", a+b);
}
