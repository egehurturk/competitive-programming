#include "/Users/egehurturk/stdc++.h"
using namespace std;

#define ll long long int

// O(√n)
ll maxPrimeFactor1(ll n) {
    ll prime = 0;
    while (n % 2 == 0) {
        prime = 2;
        n = n/2;
    }

    for (ll i = 3; i < sqrt(n); i+=2) {
        while (n % i == 0) {
            prime = max(prime, i);
            n = n/i;
        }
    }
    if (n > 2) {
        prime = max(prime, n);
    }
    return prime;
}

ll maxPrimeFactor3(ll n) {
    ll factor = 0;
    ll d = 2;
    while (n > 1) {
        while (n % d == 0) {
            factor = d;
            n /= d;
        }
        d++;
    }
    return factor;
}

// O(n)
ll maxPrimeFactor2(ll n) {
    int i = 2;
    while (n > 1) {
        if (n % i == 0) 
            n /= i;
        else
            i++;
    }
    return i;
}

ll maxPrimeFactor5(ll n) {
    ll factor = n;
    while (factor % 2 == 0) {
        factor /= 2;
    }
    for (ll f = 3; f < factor; f+=2) {
        while (factor % f == 0 && f < factor) {
            factor /= f;
        }
    }
    return factor;
}

ll maxPrimeFactor4(ll n) {
    ll factors = 0;
    ll d = 2;
    while (n > 1) {
        while (n % d == 0) {
            factors = max(factors, d);
            n /= d;
        }
        d++;
        if (d * d > n) {
            if (n > 1) 
                factors = max(factors, n);
            break;
        }
    }
    return factors;
}

ll maxPrimeFactors6(ll n) {
    ll factor = n;
    ll prime = 2;
    while (factor % 2 == 0)
        factor /= 2;
    for (ll i = 3; i <= sqrt(factor); i+=2) {
        while (factor % i == 0) {
            prime = max(prime, i);
            factor /= i;
        }
    }
    return (factor > 2) ? factor : prime;
}

int main(void) {
    ll n = 922337203369;
    ll a = 1000000000000; // 10^11
    ll b = 999999999937;
    ll j = 999999999989; // max prime number less than 10^11
    // ll maxPrime = maxPrimeFactor1(n);
    ll maxPrime2 = maxPrimeFactor2(j);
    // ll maxPrime3 = maxPrimeFactor3(n);
    // ll maxPrime4 = maxPrimeFactor4(n);
    // ll maxPrime5 = maxPrimeFactor5(n);
    // ll maxPrime6 = maxPrimeFactors6(a);
    // cout << maxPrime << endl;
    cout << maxPrime2 << endl;
    // cout << maxPrime3 << endl;
    // cout << maxPrime4 << endl;
    // cout << maxPrime5 << endl;
    // cout << maxPrime6 << endl;
}