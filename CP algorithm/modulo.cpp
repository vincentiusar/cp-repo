#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

ll modulo(ll a, ll b) {
    if (a < 0) {
        if (a % b == 0) {
            return 0;
        } else {
            ll q = (a/b) - 1;
            return abs((q*b) - a);
        }
    } else {
        return a % b;
    }
}