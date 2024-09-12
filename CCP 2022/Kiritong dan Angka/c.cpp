#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector< vector <ll> > vii;
typedef pair<ll, ll> pll;
const ll M = 1e9 + 7;

void solve() {
    string str; cin >> str;
    int k, unique = 0; cin >> k;

    int arr[10] = {0};
    
    for (int i = 0; i < str.length(); i++) {
        if (arr[int(str[i]) - '0'] == 0) unique++;
        arr[int(str[i]) - '0']++;
    }

    int total = str.length();

    if (total < k) {
        cout << "Mana Bisa Tong" << endl;
        return;
    }

    if (unique < k) {
        cout << k - unique << endl;
        return;
    }

    sort(arr, arr+10, greater<int>());

    int count = 0;
    for (int i = 0; i < k; i++) {
        count += arr[i];
    }

    cout << total - count << endl;
}

int main() {
    ll t;
    t = 1;
    // cin >> t;
    while (t--) solve();
}