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

struct people {
    ll debt;
    string name;
};

void solve() {
    ll n, k; cin >> n >> k;
    people arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].name;
        arr[i].debt = 0;
    }

    for (int i = 0; i < k; i++) {
        ld t; string to; cin >> t >> to;
        for (int j = 0; j < t; j++) {
            ld total, from; cin >> total >> from;
            ld spent = total / from;
            for (int k = 0; k < from; k++) {
                string tmp; cin >> tmp;

                for (int x = 0; x < n; x++) {
                    if (arr[x].name == tmp) {
                        arr[x].debt -= spent;
                    }
                    if (arr[x].name == to) {
                        arr[x].debt += spent;
                    }
                }
            } 
        }
    }

    ll trans = 0, total = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].debt < 0) {
            total += abs(arr[i].debt);
            trans++;
        }
    }

    cout << total << " " << trans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}