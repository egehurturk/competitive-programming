#include <iostream>

using namespace std;

int main(void)
{
    int T, a,b;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &a,&b);
        printf("%s\n", (a < b) ? "<" : (a > b) ? ">" : "=");
      
    }
}