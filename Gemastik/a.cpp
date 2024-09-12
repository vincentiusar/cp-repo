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

ll countDigit(ll n) {
    return floor(log10(n) + 1);
}

void solve() {
    ll n, x; cin >> n >> x;
    ll arr[n];

    ll mins = 1e6;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        mins = min(abs(arr[i] - x), mins);
    }

    sort(arr, arr+n);

    for (ll i = 0; i < n; i++) {
        if (abs(arr[i] - x) == mins) {
            if (arr[i] == 0) cout << "0000";
            for (int j = 0; j < 5 - countDigit(arr[i]); j++) cout << "0";
            cout << arr[i] << endl;
            if (i + 1 < n && arr[i+1] - x == mins) {
                for (int j = 0; j < 5 - countDigit(arr[i+1]); j++) cout << "0";
                cout << arr[i+1] << endl;
            }
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
