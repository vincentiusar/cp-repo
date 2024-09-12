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

bool vis[ll(1e5)+2] = {0};
vl res;
ll mins = 1e9+1;

void dfs(vll g, vl arr, ll cur) {
    vis[cur] = true;
    
    mins = min(mins, arr[cur]);
    
    for (ll adj : g[cur]) {
        if (!vis[adj]) {
            dfs(g, arr, adj);
        }
    }
}

void solve() {
    ll n, k, m; cin >> n >> k >> m;

    vll g; g.resize(n+1);
    vl arr; arr.resize(n+1);
    res.resize(n+1);

    for (ll i = 1; i <= n; i++) cin >> arr[i];

    for (ll i = 0; i < k; i++) {
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (ll i = 0; i < m; i++) {
        ll x, u, v; cin >> x >> u >> v;
        if (x == 1) {
            arr[u] = v;
        } else {
            ll total1;

            dfs(g, arr, u);
            
            if (vis[v]) { cout << 0 << endl; continue; }
            
            total1 = mins;
            mins = 1e9+1;
            dfs(g, arr, v);

            cout << total1 + mins << endl;

        }
        mins = 1e9+1;
        memset(vis, 0, n+1);
    }
    
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
