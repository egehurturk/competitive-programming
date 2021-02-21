#include <stdio.h>

int main(void)
{
    int c;
    printf("%d\n", EOF); // EOF is -1 actually
    while ((c = getchar()) != EOF) // EOF is a special name for end of file
    {
       putchar(c);
    }
}