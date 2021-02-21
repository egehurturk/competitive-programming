#include <iostream>


/*

Usually this will be the driver code for test cases. 

*/


int main(void)
{
    int TC, a, b;
    scanf("%d", &TC); // scan the number of test cases
    while (TC--) // repeat until 0
    {
        
            scanf("%d %d", &a, &b);
            printf("%d\n", a+b); // print output
        
        
    }
    // OR
    int e,d,c = 1;
    while (scanf("%d %d", &e, &d) != EOF)
        printf("Case %d: %d\n\n", c++, e+d);

    // OR another type:
    int k, ans, v;
    while (scanf("%d", &k) != EOF)
    {
        ans = 0;
        while (k--) {scanf("%d", &v); ans += v;}
        printf("%d\n", ans);
    }
}