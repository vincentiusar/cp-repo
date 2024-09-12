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

void solve() {
    ll n, m; cin >> n >> m;

    ll dp[n], arr[n];

    for (ll i = 0; i < n; i++) dp[i] = LONG_LONG_MIN;

    bool negative = 1;
    ll large = LONG_LONG_MIN;

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        
        if (arr[i] >= 0) negative = 0;

        large = max(large, arr[i]);
    }

    if (negative) { cout << large << endl; return; }

    dp[0] = max(arr[0], (ll)0);
    for (ll i = 1; i < n; i++) {
        dp[i] = max(dp[i-1], arr[i] + (i - m >= 0 ? dp[i-m] : 0));
    }

    // for (int i = 0; i < n; i++) cout << dp[i] << " ";
    cout << dp[n-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
