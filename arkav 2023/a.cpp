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

bool vis[ll(1e5)+1] = {0};

void dfs(vll g, vl arr, vl &res, ll cur, ll minss) {
    vis[cur] = true;
    
    res[cur] = min(minss, arr[cur]);
    
    for (ll adj : g[cur]) {
        if (!vis[adj]) {
            dfs(g, arr, res, adj, res[cur]);
        }
    }
}

void solve() {
    ll n, k; cin >> n >> k;

    vll g; g.resize(n+1);
    vl arr; arr.resize(n+1);
    vl res; res.resize(n+1);

    for (ll i = 1; i <= n; i++) cin >> arr[i];

    for (ll i = 0; i < n-1; i++) {
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(g, arr, res, k, 10e9+1);

    for (ll i = 1; i <= n; i++) cout << res[i] << " ";
    
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
