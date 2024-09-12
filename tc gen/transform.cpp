#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, e;
    cin >> n >> e;
    cout << n << ' ' << e << '\n';
    int x, y;
    for (int i = 0; i < n; i++) { int a; cin >> a; cout << a << " "; }
    cout << endl;
    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
}

int main() {
    solve();
}