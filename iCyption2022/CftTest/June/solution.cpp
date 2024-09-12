#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll LCM(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
    int n, q; cin >> n >> q;

    vll v;
    bool exist[2501] = {false};
    for (int i = 1; i <= 50; i++) {
        for (int j = i+1; j <= 50; j++) {
            ll lcm = LCM(i, j);
            if (lcm > 100 && !exist[lcm]) {
                v.push_back(lcm);
                exist[lcm] = true;
            }
        }
    }

    ll sume[2501] = {0};
    ll sum = 0;

    for (int j = 0; j < n; j++) {
        ll num; cin >> num;
        sum += num;
        for (int i = 1; i <= 100; i++) 
            sume[i] += (num % i == 0 ? num : 0);
        
        for (ll i : v)
            sume[i] += (num % i == 0 ? num : 0);
    }

    for (int j = 0; j < q; j++) {
        int m; cin >> m;
        ll a[m];

        for (int i = 0; i < m; i++)
            cin >> a[i];

        if (m == 1)
            cout << sume[1] - sume[a[0]];
        else 
            cout << sume[1] - sume[a[0]] - sume[a[1]] + sume[LCM(a[0], a[1])];

        cout << '\n';
    }
}