#include <iostream>

int main(void)
{
    int TC, a, b;
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
}

/*

Efficient way to test your code:

./a.out < input_file. > myoutput

where, input_file contains your sample inputs. This code will print out your outpus to a 
file called myoutput

diff myoutput output

where, output file contains sample outputs.

*/