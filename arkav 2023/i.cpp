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
    ll n, k, l, x, y, z; cin >> n >> k >> l >> x >> y >> z;

    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    vl dp[k+1];
    memset(dp, 1e9+2, k+1);

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
