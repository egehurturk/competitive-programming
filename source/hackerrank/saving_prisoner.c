#include <stdio.h>

typedef long long int ll;

int main(void) {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        ll n, m, s;
        scanf("%lld %lld %lld", &n, &m, &s);
        ll ans = 0;
        ans = (m - 1 + s - 1) % n + 1;
        printf("%lld\n", ans);   
    }
}

// (m - 1 + s - 1) % n + 1