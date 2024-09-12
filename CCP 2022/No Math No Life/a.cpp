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
    pll p1, p2; cin >> p1.first >> p1.second; cin >> p2.first >> p2.second;

    ll a, b;

    b = (p1.second - p2.second) / ((p1.first - 1) - (p2.first - 1));

    if (p1.first == 1) a = p1.second;
    else if (p2.first == 1) a = p2.second;
    else a = p1.second - ((p1.first - 1) * b);

    ll n; cin >> n;
    ll sn = 0.5*(ll(n)) * (2*a + (n-1) * b);

    cout << fixed << (ll)sn << endl;
}

int main() {
    ll t;
    t = 1;
    // cin >> t;
    while (t--) solve();
}