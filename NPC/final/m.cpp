#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t; cin >> t;

    while (t--) {
        ll n, k; cin >> n >> k;
        ll arr[n];
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            arr[i] = x;
        }
        sort(arr, arr+n);
        ll tot = 0;
        sum = 0;
        for (ll i = n-1; i >= 0; i--) {
            sum += arr[i];
            tot++;
            if (sum >= k) break;
        }
        if (sum < k) cout << -1;
        else if (k == 0) cout << 0;
        else cout << tot;
        cout << endl;
    }
}