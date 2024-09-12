#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n; cin >> n;
    ll arr[n+1] = {0};
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    ll point[n+1] = {0};
    point[1] = 1;
    for (ll i = 2; i <= n; i++) {
        ll x, k; cin >> x >> k;
        point[k] = x;
    }
    
}