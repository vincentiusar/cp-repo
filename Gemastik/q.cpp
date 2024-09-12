#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector< vector <int> > vii;
typedef pair<ll, ll> pll;
const ll M = 1e9 + 7;

vector< pll > arr;
void precompute() {
    arr.push_back({0, 0});
    int k = 1, tmp = 1;
    for (int i = 1; i < 1e5 + 1; i++) {
        if (k % 4 == 1) {
            arr.push_back({arr.back().first + 1, arr.back().second});
            tmp--;
        } else if (k % 4 == 2) {
            arr.push_back({arr.back().first, arr.back().second + 1});
            tmp--;
        } else if (k % 4 == 3) {
            arr.push_back({arr.back().first - 1, arr.back().second});
            tmp--;
        } else if (k % 4 == 0) {
            arr.push_back({arr.back().first, arr.back().second - 1});
            tmp--;
        }
        if (tmp == 0) k++, tmp = k;
    }
}

void solve() {
    int n; cin >> n;
    precompute();

    for (int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        cout << arr[tmp].first << " " << arr[tmp].second << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
