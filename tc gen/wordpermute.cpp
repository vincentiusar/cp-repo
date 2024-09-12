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

int main() {
    string s; cin >> s;
    vl arr(26, 0);

    for (ll i = 0; i < s.length(); i++) arr[ll(s[i]) - 'a']++;

    ll total = factorial(s.length(), M) % M;
    for (ll i = 0; i < 26; i++) {
        if (arr[i] > 1) 
            total *= inverse(factorial(arr[i], M), M);
    }

    cout << total % M << endl;
}