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

vii g;
bool vis[ll(1e5)] = {0};
ll total = 0;
ll power[ll(1e5)] = {0};

void dfs(int cur) {
    vis[cur] = true;
    for (int adj : g[cur])
        if (!vis[adj])
            dfs(adj);
    total += power[cur];
}

void solve() {
    int n, k; cin >> n >> k;
    g.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> power[i];

    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vl res;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            res.push_back(total);
            total = 0;
        }
    }

    sort(res.begin(), res.end(), greater<ll>());
    ll nyehehe = 0;
    for (int i = 0; i < res.size(); i++) {
        nyehehe += res[i] * (i+1);
        // cout << res[i] << " ";
    }

    cout << nyehehe << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
