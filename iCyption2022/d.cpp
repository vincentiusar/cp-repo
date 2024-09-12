#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector< vector <ll> > vii;
typedef pair<ll, ll> pll;
typedef vector< pll > vp;
const ll M = 1e9 + 7;

void solve() {
    ll n; cin >> n;
    vp arr(n+1);

    for (ll i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;

        arr[a].first = b;
        arr[a].second = c;
    }

    queue<int> q; q.push(1);
    while (!q.empty()) {
        ll i = q.front();

        cout << i << " " << arr[i].second << " " << arr[i].first << endl;
        if (arr[i].second != 0) q.push(arr[i].second);
        if (arr[i].first != 0) q.push(arr[i].first);
        
        q.pop();
    }
}

int main() {
    ll t;
    // cin >> t;
    t = 1;
    while (t--) solve();
}