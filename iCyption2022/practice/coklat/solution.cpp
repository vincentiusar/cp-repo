#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n, p, c; cin >> n >> p >> c;
    ll permen = n / p;

    ll tmp = permen;
    while (tmp >= c) {
        permen += tmp/c;
        tmp = (tmp/c) + (tmp % c);
    }
    cout << permen;
}