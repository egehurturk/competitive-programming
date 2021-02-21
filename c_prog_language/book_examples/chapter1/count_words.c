#include <stdio.h>

#define IN 1        /* inside a word */
#define OUT 0       /* outside a word*/

/* count words, lines, chars in input */
int main(void)
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc; // increase char no
        if (c == '\n')
            ++nl; // new line
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d, %d, %d\n", nl, nw, nc);
}