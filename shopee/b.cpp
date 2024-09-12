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
    ll n; cin >> n;
    ll arr[2*n];

    bool found = 0;

    for (ll i = 0; i < 2*n; i++) cin >> arr[i];

    for (ll i = 0; i < 2*n; i++) {
        for (ll j = i+1; j < 2*n; j++) {
            // cout << found << endl;
            if (arr[j] == arr[i] && j - i == n && !found) {
                found = 1;
                continue;
            }
            if (arr[j] == arr[i] && j - i == n && found) {
                cout << "no" << endl;
                return;
            }
        }
    }
    cout << "yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t; cin >> t;
    // ll t = 1;
    while (t--) solve();
}