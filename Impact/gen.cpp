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
    int n = 20;
    cout << n << '\n';
    for (int i = 0; i < n; i++)
        cout << random(1, 1000) << " \n"[i == n-1];
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