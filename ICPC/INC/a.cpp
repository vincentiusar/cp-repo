#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n; cin >> n;
    ll res = 0;
    ll arr[1000+1] = {0};
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        if (x > 0) arr[x]++;
        if (x < 0 && arr[abs(x)] == 0) {
            res++;
        } else if (x < 0 && arr[x] == 1) {
            arr[abs(x)]--;
        }
    }
    
    cout << res << endl;
}