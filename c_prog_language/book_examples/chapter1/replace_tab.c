#include <stdio.h>

#define ALPHA 'a'
#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\'

int main(void)
{
    char c;

    while ((c = getchar()) != EOF)
    {
        if (c != BACKSLASH && c != TAB && c != BACKSPACE)
            putchar(c);
        if (c == BACKSLASH) 
            printf("\\\\");

        if (c == TAB) 
            printf("\\t");


        if (c == BACKSPACE)
            printf("\\b");

        
    }
}