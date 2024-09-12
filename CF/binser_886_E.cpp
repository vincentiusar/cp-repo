#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector< vector <ll> > vll;
typedef pair<ll, ll> pll;
const ll M = 1e9 + 7;

void solve() {
    ll n, k; cin >> n >> k;
    ll arr[n];

    for (ll i = 0; i < n; i++) cin >> arr[i];

    ll l = 0, r = ll(1e9);
    while (l <= r) {
        ll m = l + (r - l) / 2;

        __int128 area = 0;
        for (ll i = 0; i < n; i++) {
            area += (arr[i]+m)*(arr[i]+m);
        }

        if (area == k) {
            cout << m/2 << endl;
            return;
        }

        if (area < k)
            l = m + 1;
        else
            r = m - 1;
        
    }
}

int main() {
    ll t;
    t = 1;
    cin >> t;
    while (t--) solve();
}