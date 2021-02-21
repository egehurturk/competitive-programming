#include <iostream>


int main(void)
{
    int k, ans, v;
    while (scanf("%d", &k) != EOF)
    {
        ans = 0;
        while (k--) 
        {
            scanf("%d", &v);
            ans += v;
        }
        printf("%d\n", ans);
    }
}