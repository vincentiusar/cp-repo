#include<iostream>
using namespace std;

using ll = long long;

void solve() {
    ll v, a, b;
    cin >> v >> a >> b;

    ll L = 1, R = 1e6 + 5;
    ll ub = 1e6 + 5;
    for (ll s = 1; s <= ub; s++) {
        ll vol = s*(s + a)*(s + b);
        if (vol == v) {
            ll y = s + a, z = s + b;
            cout << (s*y + y*z + s*z)*2 << '\n';
            return;
        }
    }
    cout << "MUSTAHIL\n";
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
}
