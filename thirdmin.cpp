#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n; cin >> n;
    ll arr[n] = {0};

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    ll x = 0, min = arr[0], res = 0;
    for (ll i = 1; i < n && x != 2; i++) {
        if (arr[i] > min) {
            min = arr[i];
            res = arr[i];
            x++;
        }
    }

    if (x != 2) cout << "sasageo";
    else cout << res;
}