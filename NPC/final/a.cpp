#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        vector <ll> arr;
        ll sum = 0;
        ll x; cin >> x;
        for (ll i = 1; i <= 13; i++) {
            if (x % i == 0) {
                sum += i;
                arr.push_back(i);
            }
        }
        
        cout << endl;
    }
}