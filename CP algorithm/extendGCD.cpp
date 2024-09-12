#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef pair<ll, ll> pll;
const ll M = 1e9 + 7;

struct tup {
    ll d, x, y;
};

tup extend_euclid(ll a, ll b) {
    tup t;
    if (b == 0) {
        t.d = a;
        t.x = 1;
        t.y = 0;
        return t;
    }
    t = extend_euclid(b, a % b);
    tup y;
    y.d = t.d;
    y.x = t.x;
    y.y = t.x - (a/b)*t.y;
    return y;
}

int main() {
    
}