#include <bits/stdc++.h>
#include "jngen.h"
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b){
    if (a > b) return 0;
    return a + rng() % (b - a + 1);
}

void test_case() {
    ll n = random(1e3, 1e4), k = random(1e3, 1e4);
    ll a = random(1e4, 1e5), b = random(1e4, 1e5);
    cout << n << " " << k << endl;
    cout << a << endl;
    for (ll i = 0; i < a; i++) {
        cout << random(1e5, 1e9) << " ";
    }
    cout << endl;
    cout << b << endl;
    for (ll i = 0; i < b; i++) {
        cout << random(1e5, 1e9) << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    // int t = 1;
    // cout << t << '\n';
    int t = random(1e2, 1e2); cout << t << '\n';
    while (t--) {
        test_case();
    }
}