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
bool stop = 0;
ll step = 0;

void dfs(vii g, int cur, int find, int prev) {
    vis[cur] = true;
    if (cur == find) {
        stop = 1;
        return;
    }
    for (int adj : g[cur]) {
        if (stop) 
            return;
        if (adj != prev) {
            step++;
            dfs(g, adj, find, cur);
            if (stop) 
                return;
            step--;
        }
    }
}

int main() {
    ll n; cin >> n;
    ll a, b, x; cin >> a >> b >> x;

    vii g(n+1);
    for (ll i = 0; i < n-1; i++) {
        ll c, d; cin >> c >> d;
        g[c].push_back(d);
        g[d].push_back(c);
    }

    dfs(g, x, a, -1);

    stop = 0;

    ll tmp = step;

    dfs(g, x, b, -1);
    if (tmp < step) step = tmp;

    stop = 0;

    dfs(g, a, b, -1);

    cout << step << endl;
}