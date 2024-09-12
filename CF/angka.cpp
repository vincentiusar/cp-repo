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
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

#define bakuretsu ios::sync_with_stdio(0), cin.tie(0);
#define fr first
#define sc second
#define sz(x) (ll) (x).size()
#define all(x) (x).begin(),(x).end()
#define rmunique(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())

void solve() {
    ll n; cin >> n;
    vl arr(n, 0);

    ll sum = 0;
    for (ll i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end(), greater<ll>());
    for (ll i = 0; i < n; i++) {
        if (sum == 0) {
            sum += arr[i];
        } else {
            ll tmp = sum;
            sum -= arr[i];
            if (sum != 0) {
                cout << tmp << endl;
                return;
            }
        }
    }

    cout << 0 << endl;

}

int main() {
    bakuretsu
    ll t;
    t = 1;
    // cin >> t;
    while (t--) solve();
}