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

void solve() {
    string str; cin >> str;

    int n = str.length();

    int arr[n];

    for (int i = n-1; i >= 0; i--) {
        arr[i] = str[i] - '0';
    }

    sort(arr, arr+n);

    int id = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            id = i; break;
        }
    }

    sort(arr + id, arr+n, greater<int>());

    int sub[n];
    copy (arr, arr+n, sub);

    for (int i = n-1; i > 0; i--) {
        if (sub[i] != sub[i-1]) {
            swap(sub[i], sub[i-1]);
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << sub[i];
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;

    vector <int> res;
    for (int i = n-1; i > 0; i--) {
        if (arr[i] - sub[i] < 0) {
            res.push_back(10 + arr[i] - sub[i]);
            arr[i-1]--;
        } else {
            res.push_back(arr[i] - sub[i]);
        }
    }

    for (int i = res.size(); i >= 0; i--) {
        cout << res[i];
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}