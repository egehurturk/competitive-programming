#include <stdio.h>

int main(void)
{
    int c, nt=0, ns=0, nl=0;

    while ((c = getchar()) != EOF) 
    {
        if (c == ' ')
            ++ns;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
        else
            ;
    }
    printf("No of tabs: %d, no of spaces: %d, no of lines: %d\n", nt, ns, nl);
}