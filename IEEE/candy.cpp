#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

struct candy {
    ll count, prize;
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n, k; cin >> n >> k;
    candy arr[n];
    for (ll i = 0; i < n; i++) {
        cin >> arr[i].count >> arr[i].prize;
    }
    
}