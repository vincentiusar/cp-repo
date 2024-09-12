#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;

    if(n % 3 == 2 && m % 3 == 2) {
        cout << n*m/3 - 1;
    } else {
        cout << n*m/3;
    }
}