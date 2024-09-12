#include <bits/stdc++.h>

using namespace std;

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

ll calculateMod(ll p, ll q, ll k, ll m) {
    ll s = power(p, k, M) * power(k, q, M);
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll p, q;
    ll n, m, total = 0;
    
    cin >> p >> q >> n >> m;
    
    for (ll i = 1; i <= n; i++) {
        total += calculateMod(p, q, i, m);
    }
    
    cout << total % m;
    return 0;
}