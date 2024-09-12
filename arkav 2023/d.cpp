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
ll mins = 1e9+2;

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

    vl res;
    vll g; g.resize(n+1);
    vl arr; arr.resize(n+1);

    for (ll i = 1; i <= n; i++) cin >> arr[i];

    for (ll i = 0; i < k; i++) {
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // for (int i = 1; i <= n; i++) {
    //     if (!vis[i]) {
    //         dfs(g, arr, i);
    //         res.push_back(mins);
    //         mins = 1e9+2;
    //     }
    // }
    // memset(vis, 0, n+1);

    for (int i = 1; i <= res.size(); i++) {
        cout << res[i] << " ";
    }
    memset(vis, 0, n+1);

    for (ll i = 0; i < m; i++) {
        ll x, u, v; cin >> x >> u >> v;
        if (x == 1) {
            arr[u] = v;
        } else {
            queue<ll> q;
            q.push(u);
            vis[u] = 1;
            ll mins1 = arr[u];
            while (!q.empty()) {
                ll cur = q.front();
                q.pop();

                for (ll adj : g[cur]) {
                    if (!vis[adj]) {
                        mins1 = min(mins1, arr[adj]);
                        q.push(adj);
                        vis[adj] = 1;
                    }
                }
            }
            
            if (vis[v]) { cout << 0 << endl; continue; }

            queue<ll> qu;
            qu.push(v);
            vis[v] = 1;
            ll mins2 = arr[v];
            while (!qu.empty()) {
                ll cur = qu.front();
                qu.pop();

                for (ll adj : g[cur]) {
                    if (!vis[adj]) {
                        mins2 = min(mins2, arr[adj]);
                        qu.push(adj);
                        vis[adj] = 1;
                    }
                }
            }

            // for (int i = 0; i < res.size(); i++) {
            //     if (res[i] < 0) {
            //         mins2 -= 2*res[i];
            //     }
            // }
            cout << mins1 + mins2 << endl;
        }
        memset(vis, 0, n+1);
    }
    
    cout << "\n";
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
