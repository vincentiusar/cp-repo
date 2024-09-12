#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n; cin >> n;
    while (n--) {
        ll x; cin >> x;
        bool dice = 0;
        ld d1 = 0, d2 = 0;
        ll ta = 0, tb = 0;
        for (ll i = 0; i < x; i++) {
            ld a, b; cin >> a >> b;
            ta += a;
            tb += b;
            if (!dice) {
                if (a == 6) d1 += ld(ld(2)/ld(7));
                else d1 += ld(ld(1)/ld(7));
                if (b == 6) d2 += ld(ld(2)/ld(7));
                else d2 += ld(ld(1)/ld(7));
            } else {
                if (a == 6) d2 += ld(ld(2)/ld(7));
                else d2 += ld(ld(1)/ld(7));
                if (b == 6) d1 += ld(ld(2)/ld(7));
                else d1 += ld(ld(1)/ld(7));
            }
            if (ta != tb) {
                dice = !(dice);
            }
        }
        d1 /= ld(x);
        d2 /= ld(x);
        if (d1 > d2) cout << 1 << endl;
        else cout << 2 << endl;
    }
}