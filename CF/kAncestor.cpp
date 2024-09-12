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
    ll n; cin >> n;
    vl parent(n);
    for (ll i = 0; i < n; i++) cin >> parent[i];

    int LOG = 30;
    vll up(n, vl(LOG));
    vl depth(n, 0);
    parent[0] = 0;
    for (int i = 0; i < n; i++) {
        up[i][0] = parent[i];
        if (i != 0) depth[i] = depth[parent[i]] + 1;
        for (int j = 1; j < LOG; j++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }

    ll q; cin >> q;
    while (q--) {
        ll node, k; cin >> node >> k;
        if (depth[node] < k) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                node = up[node][i];
            }
        }
        cout << node << endl;
    }
}

int main() {
    bakuretsu
    ll t;
    t = 1;
    // cin >> t;
    while (t--) solve();
}