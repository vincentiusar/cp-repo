#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector< vector <ll> > vii;
typedef pair<ll, ll> pll;
const ll M = 1e9 + 7;

void solve() {
    ll a, b, aorb; cin >> a >> b >> aorb;

    ll res = aorb - a - b;
    res *= -1;

    if (res < 0 || res > aorb) {
        cout << "Boong lu ya" << endl;
        return;
    }

    cout << res << endl;
}

int main() {
    ll t;
    t = 1;
    // cin >> t;
    while (t--) solve();
}