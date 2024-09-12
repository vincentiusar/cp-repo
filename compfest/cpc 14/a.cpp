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
    ll n, m; cin >> n >> m;

    if (m == 2 || n == 2) {
        cout << (n*m) / 2;
        return;
    }
    ll total = ((n-1) * (m-1)) + 2;
    cout << total << endl;    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
