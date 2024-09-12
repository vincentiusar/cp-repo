#include <bits/stdc++.h>
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
    ll a = random(1000, 100000), b = random(1000, 100000);
    ll aAndb = random(0, min(a, b));
    ll aOrb = a + b - aAndb;

    cout << a << " " << b << " " << aOrb;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t = 1;
    // cout << t << '\n';
    // int t = random(1, 1); cout << t << '\n';
    while (t--) {
        test_case();
    }
}