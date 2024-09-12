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
    ll n, k, x; cin >> n >> k >> x;
    vl arr(n, 0);

    for (ll i = 0; i < n; i++) arr[i] = i+1;
    for (ll i = 0; i < k; i++) {
        ll a, b; cin >> a >> b;

        ll er = arr[a-1];
        arr.erase(arr.begin()+a-1);
        arr.insert(arr.begin()+b-1, er);
    }

    for (ll i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << i+1 << endl;
            return;
        }
    }
}

int main() {
    bakuretsu
    ll t;
    t = 1;
    // cin >> t;
    while (t--) solve();
}