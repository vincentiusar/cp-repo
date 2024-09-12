#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, d; cin >> n >> d;

    if (n <= 1) {
        cout << n << endl; return 0;
    }

    for (ll i = 0; i < d; i++) {
        n = n * 3 / 2;
    }

    cout << n << endl;
}