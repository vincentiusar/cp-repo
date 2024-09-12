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
typedef map<ll, ll> mll;
// using lll = __int128;
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
    ll n, q; cin >> n >> q;

    vl arr(n);
    for (ll &x: arr) cin >> x;

    ll bebas = 1;
    while (bebas < n)
        bebas *= 2;

    n = bebas;

    vl tree(2*n), lazy(2*n);
    for (ll i = 0; i < arr.size(); i++)
        tree[i+n] = arr[i];

    for (ll i = n-1; i > 0; i--) 
        tree[i] = tree[i*2] + tree[i*2 + 1];

    function <ll(ll, ll, ll, ll, ll)> query = [&](ll i, ll l, ll r, ll qleft, ll qright) {
        if (lazy[i]) {
            tree[i] += lazy[i] * (r - l + 1);
            if (l != r)
                lazy[i*2] += lazy[i], lazy[i*2 + 1] += lazy[i];
            lazy[i] = 0;
        }
        if (l > qright || r < qleft) return (ll)0;
        if (qleft <= l && r <= qright) return tree[i];

        ll left = i * 2, right = i * 2 + 1;
        return query(left, l, (l+r)/2, qleft, qright) 
            + query(right, (l+r)/2 + 1, r, qleft, qright);
    };

    function <void(ll, ll, ll, ll, ll, ll)> update = [&](ll i, ll l, ll r, ll qleft, ll qright, ll val) {
        if (l > qright || r < qleft) return;
        if (qleft <= l && r <= qright) { lazy[i] += val; return; }

        ll left = i * 2, right = i * 2 + 1;
        update(left, l, (l+r)/2, qleft, qright, val);
        update(right, (l+r)/2 + 1, r, qleft, qright, val);
    };

    while (q--) {
        ll p; cin >> p;

        if (p == 1) {
            ll a, b, c; cin >> a >> b >> c;
            a--; b--;
            update(1, 0, n-1, a, b, c);
        } else {
            ll x; cin >> x;
            x--;
            cout << query(1, 0, n-1, x, x) << endl;
        }
    }
}

int main() {
    bakuretsu
    ll t;
    t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "CASE #" << i << " : ";
        solve();
    }
}