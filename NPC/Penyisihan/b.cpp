#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

ll combination(ll n, ll r) {
    if (r > n)
        return 0;
    ll m = 1000000007;
    ll inv[r + 1] = { 0 };
    inv[0] = 1;
    if(r+1>=2)
    inv[1] = 1;

    for (ll i = 2; i <= r; i++) {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }
 
    ll ans = 1;
 
    for (ll i = 2; i <= r; i++) {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }
 
    for (ll i = n; i >= (n - r + 1); i--) {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}

ll main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n, k; cin >> n >> k;
    if (n < (2 * k) - 1) {
        cout << 0 << endl;
        return 0;
    }
    ll num = n - k + 1;
    cout <<  combination(num, k) << endl;
}
