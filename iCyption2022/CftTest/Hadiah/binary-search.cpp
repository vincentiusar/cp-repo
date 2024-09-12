#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

void solve() {
    ll v, a, b;
    cin >> v >> a >> b;

    auto calcLuasPermukaan = [&](ll x, ll y, ll z) -> ll {
        return (x*y + y*z + x*z)*2;
    };

    ll L = 1, R = 1e6 + 5;
    while (L <= R) {
        ll s = (L + R)/2;
        ll vol = s*(s + a)*(s + b);
        if (vol == v) {
            cout << calcLuasPermukaan(s, s+a, s+b) << '\n';
            return;
        } else if (vol < v) {
            L = s + 1;
        } else {
            R = s - 1;
        }
    }
    cout << "MUSTAHIL\n";
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
}
