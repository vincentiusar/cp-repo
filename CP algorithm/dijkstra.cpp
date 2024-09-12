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
    ll n, e; cin >> n >> e;

    vector < vector <pll> > g(n + 1);
    for (ll i = 0; i < e; i++) {
        ll a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    ll src; cin >> src;
    set<pll> q;
    vl dist(n+1, 1e18);

    q.insert({0, src});

    while (!q.empty()) {
        // ll totalCost = q.begin()->fr, cur = q.begin()->sc;
        auto [totalCost, cur] = *q.begin();
        q.erase(q.begin());

        for (auto [adj, w] : g[cur]) {
            if (totalCost + w < dist[adj]) {
                q.erase({dist[adj], adj});
                dist[adj] = totalCost + w;
                q.insert({dist[adj], adj});
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        if (i != src) {
            if (dist[i] != 1e18) cout << dist[i] << " ";
            else cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    bakuretsu
    ll t;
    // t = 1;
    cin >> t;
    while (t--) solve();
}