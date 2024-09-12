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
const ll M = 1e9 + 7;

#define bakuretsu ios::sync_with_stdio(0), cin.tie(0);
#define fr first
#define se second
#define sz(x) (ll) (x).size()
#define rmunique(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())

void solve() {
    ll n, k; cin >> n >> k;
    vector < pair<ll, ll> > arr(n);
    vl pref(n);

    for (ll i = 0; i < n; i++) {
        cin >> arr[i].fr;
        pref[i] = (i == 0 ? arr[i].fr : pref[i-1] + arr[i].fr);
    }
    for (ll i = 0; i < n; i++) cin >> arr[i].se;

    ll res = 0;

    ll l = 0, r = 0;
    for (ll i = 1; i <= n; i++) {
        if (i == n || arr[i-1].se % arr[i].se != 0) {
            r = i-1;
            for (ll j = l; j <= r; j++) {
                ll left = j, right = r, thr = -1;
                while (left <= right) {
                    ll mid = (left + right) / 2;

                    ll sum = pref[mid] - (j - 1 < 0 ? 0 : pref[j-1]);

                    if (sum <= k) {
                        thr = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                res = max(res, thr-j+1);
            }
            l = i;
        }
    }

    cout << res << endl;

}

int main() {
    bakuretsu
    ll t;
    // t = 1;
    cin >> t;
    while (t--) solve();
}