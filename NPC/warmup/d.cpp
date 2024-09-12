#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

struct graph {
    ll a, b, c;
};

bool compare(graph a, graph b) {
    if (a.c < b.c) return 1;
    return 0;
}

int main() {
    ll n, m; cin >> n >> m;
    graph arr[n] = {0}; 
    ll group[n];
    for (ll i = 0; i < n; i++) {
        group[i] = i;
    }
    ll sum = 0;
    for (ll i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        arr[i].a = a, arr[i].b = b, arr[i].c = c;
        sum += c;
    }
    sort(arr, arr+m, compare);

    ll res = 0;
    for (ll i = 0; i < m; i++) {
        
    }
    cout << sum - res;
}
