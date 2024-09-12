#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector< vl > vll;
typedef vector<bool> vb;
typedef vector< vb > vbb;
typedef pair<ll, ll> pll;
using lll = __int128;
const ll M = 1e9 + 7;
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

#define bakuretsu ios::sync_with_stdio(0), cin.tie(0);
#define fr first
#define sc second
#define sz(x) (ll) (x).size()
#define all(x) (x).begin(),(x).end()
#define rmunique(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())

void solve() {
    ll n, x; cin >> n >> x;
    vll dp(n, vl(x+1, 0));
    vl arr(n);

    for (ll i = 0; i < n; i++) cin >> arr[i];

    dp[0][0] = 1;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <= x; j++) {
            if (i == 0 && j == 0) continue;
            if (j == 0) dp[i][j] = 1;
            else if (i == 0) {
                if (j == arr[i]) dp[i][j] = 1;
            }
            else {
                if (j - arr[i] < 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
            }
        }
    }

    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j <= x; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n-1][x] << endl;
}

int main() {
    bakuretsu
    ll t;
    t = 1;
    // cin >> t;
    while (t--) solve();
}