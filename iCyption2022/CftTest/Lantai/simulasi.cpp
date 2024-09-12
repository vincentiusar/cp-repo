#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    // if (m > n) swap(n, m);

    ll cnt = (n/3) * m;

    int row = n - (n % 3);
    for (int i = row; i < n; i++)
        for (int j = 0; j + 2 < m; j += 3)
            cnt++;

    cout << cnt << '\n';
}
