#include <stdio.h>
#include <math.h>

#define ll long long int

ll maxPrimeFactors(ll n) {
    ll factor = n;
    ll prime = 2;
    while (factor % 2 == 0)
        factor /= 2;
    for (ll i = 3; i <= sqrt(factor); i+=2) {
        while (factor % i == 0) {
            prime = fmax(prime, i);
            factor /= i;
        }
    }
    return (factor > 2) ? factor : prime;
}

int main(void) {
    ll num;
    scanf("%lld", &num);
    ll maxPrime = maxPrimeFactors(num);
    printf("%lld\n", maxPrime);
}