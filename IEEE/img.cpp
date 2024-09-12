#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

int main() {
    ll t; cin >> t;
    while (t--) {
        ll p, l; cin >> p >> l;
        ll arr[p][l] = {0};
        for (ll i = 0; i < p; i++) {
            for (ll j = 0; j < l; j++) {
                string str; cin >> str;
                arr[i][j] = count(str.begin(), str.end(), "#");
            }
            sort(arr[i], arr[i]+l);
        }
        ll p2, l2; cin >> p2 >> l2;
        ll arr2[p2][l2] = {0};
        for (ll i = 0; i < p2; i++) {
            for (ll j = 0; j < l2; j++) {
                string str; cin >> str;
                arr2[i][j] = count(str.begin(), str.end(), "#");
            }
            sort(arr2[i], arr2[i]+l2);
        }
        ll masx = 0;
        
    }
}