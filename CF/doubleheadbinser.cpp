#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector< vl > vll;
typedef vector<bool> vb;
typedef vector< vb > vbb;
typedef pair<ll, ll> pll;
// using lll = __int128;
const ll M = 1e9 + 7;
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

#define bakuretsu ios::sync_with_stdio(0), cin.tie(0);
#define fr first
#define sc second
#define sz(x) (ll) (x).size()
#define all(x) (x).begin(),(x).end()
#define rmunique(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())

void solve() {
    ll n, k; cin >> n >> k;
    vl arr(n);

    for (ll i = 0; i < n; i++) cin >> arr[i];

    if (k >= 3) {
        cout << 0 << endl;
        return;
    }

    rmunique(arr);
    if (arr.size() == 1) arr.push_back(arr[0]);
    ll dif = arr[0];
    for (ll i = 0; i < arr.size()-1; i++) {
        dif = min(dif, abs(arr[i+1]-arr[i]));
    }

    if (k == 1) {
        cout << min(arr[0], dif) << endl;
    } else {
        ll res = dif;
        for (ll i = 0; i < arr.size(); i++) 
            for (ll j = i + 1; j < arr.size(); j++) {
                ll x = abs(arr[i] - arr[j]);
                ll l = 0, r = arr.size() - 1, t = 0;
                while (l <= r) {
                    ll m = (l + r) / 2;

                    if (x <= arr[m]) {
                        r = m - 1;
                        t = m;
                    } else {
                        l = m + 1;
                    }
                }
                res = min(res, abs(x - arr[t]));

                l = 0, r = arr.size() - 1, t = 0;
                while (l <= r) {
                    ll m = (l + r) / 2;

                    if (x >= arr[m]) {
                        t = m;
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }

                res = min(res, abs(x - arr[t]));
            }

        cout << res << endl;
    }
}

int main() {
    bakuretsu
    ll t;
    t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "CASE #" << i << " : ";
        solve();
    }
}