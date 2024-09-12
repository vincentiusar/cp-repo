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

ll power(ll x, ll y, ll p) {
    ll res = 1;    
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}

ll inverse(ll a, ll p) {
    return power(a, p-2, p);
}

ll factorial(ll n, ll p) {
    ll result = 1;
    for (ll i = 1; i <= n; i++)
        result = (result * i) % p;
 
    return result;
}

void solve() {
    ll n; cin >> n; n %= M;
    map<ll, ll> fact;

    ll total = 0;
    while (n % 2 == 0) {
        if (fact.find(2) == fact.end()) {
            fact.insert({2, 1});
        } else {
            fact[2]++;
        }
        total++;
        n = n/2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            if (fact.find(2) == fact.end()) {
                fact.insert({i, 1});
            } else {
                fact[i]++;
            }
            total++;
            n = n/i;
        }
    }

    if (n > 2) {
        if (fact.find(2) == fact.end()) {
            fact.insert({n, 1});
        } else {
            fact[n]++;
        }
        total++;
    }

    ll inv = 1;
    for (auto i = fact.cbegin(); i != fact.cend(); i++) {
        // cout << i->first << " " << i->second << endl;
        inv = (inv * (factorial(i->second, M))) % M;
    }
    // cout << total << endl;

    ll res = ((factorial(total, M) * inverse(inv, M)) % M);
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
