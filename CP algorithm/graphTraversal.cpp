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

bool vis[ll(1e5)] = {0};

void solve() {
    int n, c; cin >> n >> c;
    vector<vector<int>> g;
    g.resize(n+1);
    for (int i = 0; i < c; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void bfs(vii g, int src) {
    
    queue<int> q;
    q.push(src);  // c = source
    vis[src] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int adj : g[cur]) {
            if (!vis[adj]) {
                q.push(adj);
                vis[adj] = 1;
            }
        }
    }
}

void dfs(vii g, int cur) {
    vis[cur] = true;
    for (int adj : g[cur])
        if (!vis[adj])
            dfs(g, adj);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}