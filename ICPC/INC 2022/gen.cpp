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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b){
    if (a > b) return 0;
    return a + rng() % (b - a + 1);
}

int main() {
    int n = random(2, 50);

    cout << n << endl;

    for (int i = 0; i < n; i++) {
        if (random(1, 100) <= 70) {
            cout << 2 << " ";
        } else {
            cout << random(1, 8) << " ";
        }
    }
}