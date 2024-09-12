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

    queue<ll> q;
    q.push(k);
    vis[k] = 1;
    res[k] = arr[k];
    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        for (ll adj : g[cur]) {
            if (!vis[adj]) {
                res[adj] = min(res[cur], arr[adj]);
                q.push(adj);
                vis[adj] = 1;
            }
        }
    }

    for (ll i = 1; i <= n; i++) cout << res[i] << " ";
    
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
