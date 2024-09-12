#include <bits/stdc++.h>

using namespace std;

#define init ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

ll power(ll x, unsigned int y, ll p) {
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

long long kombinasi(long long n, int r, int p) {
    if (r == 0) return 1;
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % p;
    }
 
    return (fac[n] * inverse(fac[r], p) % p * inverse(fac[n - r], p) % p) % p;
}

int main()
{
    int t, n, m, k, hasil = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m >> k;
        hasil += kombinasi(n+m, k, M);
    }
    cout << hasil << endl;
}