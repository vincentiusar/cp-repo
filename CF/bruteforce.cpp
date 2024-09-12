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

void solve() {
    ll l, r, m; cin >> l >> r >> m;

    ll a, b; cin >> a >> b;

    if (a == b) { 
        cout << 0 << endl;
        return;
    }

    if (r-l < m) {
        cout << -1 << endl;
        return;
    }

    // cout << abs(a-b) << endl;
    if (abs(a-b) < m) {
        if (abs(a-l) < m && abs(a-r) < m) {
            cout << -1 << endl;
            return;
        } else if (abs(b-l) < m && abs(b-r) < m) {
            cout << -1 << endl;
            return;
        }

        if (a > b) swap(a, b);

        if (r - b < m) {
            cout << 3 << endl;
            return;
        }
        cout << 2 << endl;
        return;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    ll t;
    // t = 1;
    cin >> t;
    while (t--) solve();
}