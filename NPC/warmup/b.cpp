#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;


ll powMod(ll a, ll b, ll p) {
    a %= p;
    if (a == 0) return 0;
    ll res = 1;
    while(b > 0){
        if (b & 1) res = (res*a)%p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

ll inverse(ll a, ll p) {
    return powMod(a, p-2, p);
}

ll LCM(ll arr[], ll n) {
    ll ans = arr[0];
 
    for (ll i = 1; i < n; i++)
        ans = ( (arr[i] * ans) % M ) * inverse( (__gcd(arr[i], ans) % M), M ) % M;
 
    return ans;
}

int main() {
    ll n;
    cin >> n;
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll arr[n];
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << LCM(arr, n) << endl;
}