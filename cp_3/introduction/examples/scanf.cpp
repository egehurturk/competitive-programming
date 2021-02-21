#include <cstdio>

using namespace std;

int N; // use global variables in contests
char x[110]; // set array size a bit larger than needed

int main(void)
{
    scanf("%d\n", &N);
    while (N--)  // Loop from N, N-1, N-2, ..., 0
    {
        scanf("%.[0-9]...\n", x);
        printf("the digits are 0.%s\n", x);
    }
}