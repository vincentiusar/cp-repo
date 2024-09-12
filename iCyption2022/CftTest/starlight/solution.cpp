#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector< vector <int> > vii;
typedef pair<ll, ll> pll;
const ll M = 1e9 + 7;

ll dp[ll(1e6+1)];

void solve() {
    for (ll i = 0; i <= 1e6; i++) dp[i] = 1e9;

    ll a, b, c; cin >> a >> b >> c;
    ll t; cin >> t;
    
    dp[a] = 1; dp[b] = 1; dp[c] = 1;
    dp[0] = 0;
    
    for (ll i = 1; i <= 1e6; i++) {
        if (i - a >= 0) dp[i] = min(dp[i-a] + 1, dp[i]);
        if (i - b >= 0) dp[i] = min(dp[i-b] + 1, dp[i]);
        if (i - c >= 0) dp[i] = min(dp[i-c] + 1, dp[i]);
    }

    // for (int i = 0; i < 20; i++) cout << dp[i] << " ";

    while (t--) {
        ll n; cin >> n;

        cout << (dp[n] == 1e9 ? 0 : dp[n]) << endl;
    }
}

int main() {
    ll t;
    t = 1;
    // cin >> t;

    while (t--) solve();
}