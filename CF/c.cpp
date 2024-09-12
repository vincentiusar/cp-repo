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
    int n, k; cin >> n >> k;
    ll arr[n];

    for (int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        arr[i] = tmp + i + 1;
    }

    sort(arr, arr+n);

    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (k - arr[i] >= 0) {
            res++;
            k -= arr[i];
        } else {
            break;
        }
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t;
    // t = 1;
    cin >> t;
    while (t--) solve();
}