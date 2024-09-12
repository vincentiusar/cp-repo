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
    ll n, k, m; cin >> n >> k >> m;

    k %= 10; m %= 10;

    if (n == 1) {
        cout << "Kedua" << endl;
    }

    if (k * m == 1) {
        cout << "Pertama" << endl;
        return;
    }
    cout << "Kedua" << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}