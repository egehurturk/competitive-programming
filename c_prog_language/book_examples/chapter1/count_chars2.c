#include <stdio.h>

int main(void)
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
    {
        ;
    }
    printf("%0.f\n", nc);
}