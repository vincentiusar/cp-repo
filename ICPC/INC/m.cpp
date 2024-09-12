#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll k, s, n, sisa;
    cin >> k >> s >> n;

    sisa = n - (k * s);

    if (sisa < 0) {
        cout << "NO" << endl;
    }
    else if (sisa <= (k - 2) * s) {
        cout << "YES" << endl;
    }
    else {
        sisa -= k - 2;
        if (sisa % 2 == 1 && s == 1) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}