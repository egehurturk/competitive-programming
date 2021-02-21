#include <stdio.h>

#define IN 1
#define OUT 0 
#define ALPHA 'a'


int main(void)
{
    int c, nw, state;
    nw = 0;
    state = OUT;
    while ((c = getchar()) != EOF)
    {
        // start with state OUT
        
        if (c == ' ' || c == '\t' || c == '\n')
           if (state == IN) 
           {
               putchar('\n');
               state = OUT;
           }

        
        // if char is inside a word
        if (state == OUT) 
        {
             state = IN;
             putchar(c);
        }

        else
            putchar(c);
    }
}

/*
 * Prints input one word per line
 * 1. Word? state out olana kadar print et?
 * 2. print new line
 * 
 */