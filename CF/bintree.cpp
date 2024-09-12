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

void dfsAdd(map<ll, pll> &g, ll cur, ll ins) {
    if (ins < cur) {
        if (g[cur].fr == 0) g[cur].fr = ins;
        else {
            dfsAdd(g, g[cur].fr, ins);
        }
    } else {
        if (g[cur].sc == 0) g[cur].sc = ins;
        else {
            dfsAdd(g, g[cur].sc, ins);
        }
    }
}

void printPre(map<ll, pll> &g, ll cur, ll n) {
    if (cur != 0) {
        cout << cur-1 << " ";
        printPre(g, g[cur].fr, n);
        printPre(g, g[cur].sc, n);
    }
}

void printIn(map<ll, pll> &g, ll cur, ll n) {
    if (cur != 0) {
        printIn(g, g[cur].fr, n);
        cout << cur-1 << " ";
        printIn(g, g[cur].sc, n);
    }
}

void printPost(map<ll, pll> &g, ll cur, ll n) {
    if (cur != 0) {
        printPost(g, g[cur].fr, n);
        printPost(g, g[cur].sc, n);
        cout << cur-1 << " ";
    }
}

void solve() {
    ll n; cin >> n;
    map<ll, pll> g;

    ll root; cin >> root; root++;
    for (ll i = 1; i < n; i++) {
        ll a; cin >> a; a++;
        dfsAdd(g, root, a);
    }

    cout << "Pre.: "; printPre(g, root, n);
    cout << endl;
    cout << "In..: "; printIn(g, root, n);
    cout << endl;
    cout << "Post: "; printPost(g, root, n);
    cout << endl;
}

int main() {
    bakuretsu
    ll t;
    t = 1;
    cin >> t;
    while (t--) solve();
}