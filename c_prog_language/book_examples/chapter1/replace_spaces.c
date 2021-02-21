#include <stdio.h>

#define NON_BLANK 'a'

int main(void)
{
    char c, lastc;

    lastc = NON_BLANK;

    while ((c = getchar()) != EOF)
    {
        // if c is non-blank, then display that
        if (c != ' ')
           putchar(c);

        // if c is blank...
        if (c == ' ')
            // but previous one is not blank, display that
            if (lastc != ' ')
                putchar(c);
            // but previous one is also blank, do not display the blank again. (Replace blank)
        
        // lastc becomes c
        lastc = c;
        
    }
}