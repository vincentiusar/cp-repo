#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
const ull M = 1e9 + 7;

ull power(ull x, ull y, ull p) {
    ull res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

ull inverse(ull a, ull p) {
    return power(a, p-2, p);
}

int main() {
    ull a, b; cin >> a >> b;
    ull c = b-a+1;
    a = a % M; b = b % M;

    ull res = (((((a+b) % M) * ((c) % M)) % M) * inverse(2, M)) % M;
    cout << res << endl;
}