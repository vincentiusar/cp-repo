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

bool comp(pair<ll, pll> a, pair<ll, pll> b) {
    return a.sc.sc < b.sc.sc;
}

vl parent;
ll findRoot(ll v) {
    ll root = v;
    while (root != parent[root]) root = parent[root];

    while (v != root) {
        ll next = parent[v];
        parent[v] = root;
        v = next;
    }

    return root;
}

void unify(ll a, ll b) {
    ll root_a = findRoot(a);
    ll root_b = findRoot(b);
    if (root_a != root_b) {
        parent[root_b] = root_a;
    }
}

void solve() {
    ll n, e; cin >> n >> e;

    vector < vector <pll> > g(n+1);
    vector < pair <ll, pll> > pw(e);
    parent.resize(n+1);

    for (ll i = 1; i <= n; i++) parent[i] = i;

    for (ll i = 0; i < e; i++) {
        ll a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
        pw[i] = {a, {b, w}};
    }

    sort(pw.begin(), pw.end(), comp);

    ll total = 0;
    for (ll i = 0; i < e; i++) {
        if (findRoot(pw[i].fr) != findRoot(pw[i].sc.fr)) {
            total += pw[i].sc.sc;
            unify(pw[i].fr, pw[i].sc.fr);
        }
    }

    cout << total << endl;
}

int main() {
    bakuretsu
    ll t;
    t = 1;
    // cin >> t;
    while (t--) solve();
}