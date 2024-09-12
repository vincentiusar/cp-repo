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
typedef map<ll, ll> mll;
// using lll = __int128;
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
    ll n, m; cin >> n >> m;
    vector<string> g(n);

    for (ll i = 0; i < n; i++) 
        cin >> g[i];

    function <bool (ll, ll)> isInside = [&](ll a, ll b) {
        return a >= 0 && b >= 0 && a < n && b < m;
    };

    ll mins = 1e18;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (g[i][j] != '#' && g[i][j] != 'X') {
                ll maxs = -1;
                vll vis(n, vl(m, 0));

                queue <pll> q;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto [a, b] = q.front();
                    q.pop();

                    for (ll k = 0; k < 4; k++) {
                        ll a_ = a + moveX[k], b_ = b + moveY[k];
                        if (isInside(a_, b_) && !vis[a_][b_] && g[a_][b_] != '#') {
                            vis[a_][b_] = vis[a][b] + 1;
                            q.push({a_, b_});
                            if (g[a_][b_] == 'X') maxs = max(maxs, vis[a_][b_]-1);
                        }
                    }
                }
                mins = min(mins, maxs);
            }
        }
    }

    cout << mins << endl;
}

int main() {
    bakuretsu
    ll t;
    t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "CASE #" << i << " : ";
        solve();
    }
}