#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

ll power(ll x, ll y, ll p) {
    ll res = 1;    
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}

ll inverse(ll a, ll p) {
    return power(a, p-2, p);
}

ll factorial(ll n, ll p) {
    ll result = 1;
    for (ll i = 1; i <= n; i++)
        result = (result * i) % p;
 
    return result;
}

// faktorial pakai invers cuman kalau ada pembagian
// A! / B! jadi A! * invers(B!)

int main() {
    cout << ((factorial(16, 1000000007) % 1000000007) * (inverse(factorial(14, 1000000007), 1000000007) % 1000000007)) % 1000000007;
}