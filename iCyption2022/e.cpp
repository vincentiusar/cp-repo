#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector< vector <ll> > vii;
typedef pair<ll, ll> pll;
typedef vector< pll > vp;
const ll M = 1e9 + 7;

const ld pi = 3.1415926535;

ld sins(ld n) {
    ld rad = (n / 180.0) * ((ld) pi);
    ld res = sin(rad);
    if (abs(res) < 0.00001) return 0;
    return res;
}

ld coss(ld n) {
    ld rad = (n / 180.0) * ((ld) pi);
    ld res = cos(rad);
    if (abs(res) < 0.00001) return 0;
    return res;
}

ld pythagoras(ld a, ld b) {
    return sqrtl(a*a + b*b);
}

void solve() {
    ll n; cin >> n;

    ld X = 0, Y = 0;

    for (ll i = 0; i < n; i++) {
        ld dist, deg; cin >> dist >> deg;

        X += dist * coss(deg);
        Y += dist * sins(deg);
    }

    cout << fixed << setprecision(4) << pythagoras(X, Y) << " " << atan(Y/X) * 180 / pi;
}

int main() {
    ll t;
    // cin >> t;
    t = 1;
    while (t--) solve();
}