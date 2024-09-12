#include <bits/stdc++.h>

using namespace std;

#define init ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

ll f(ld x, ld m) {
    return x - (floor(x/m)) * m;
}

int main() {
    ll a, b; cin >> a >> b;
    ll arr[a+1];
    for (ll i = 1; i <= a; i++) {
        cin >> arr[i];
    }
    ll arr2[a+1][a+1];
    fill(arr2[0], arr2[0] + (a+1)*(a+1), -1);
    ll res = 0;
    for (ll i = 1; i <= a; i++) {
        ll minim = __LONG_LONG_MAX__;
        for (ll j = i + 1; j <= a; j++) {
            arr2[i][j] = f(arr[i] - arr[j], b);
            arr2[j][i] = f(arr[j] - arr[i], b);
        }
    }
    cout << res << endl;
    for (ll i = 1; i <= a; i++) {
        for (ll j = 1; j <= a; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}