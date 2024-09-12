#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef pair<ll, ll> pll;

const ll M = 1e9 + 7;

ll add(ll a, ll b) { return (a + b) % M; }
ll mul(ll a, ll b) { return (a * b) % M; }

struct matrix {
    vector < vector<ll> > mat;
};

matrix multi(matrix a, matrix b) {
    matrix res; ll n = b.mat[0].size();
    for (ll i = 0; i < n; i++) {
        vl tmp(n);
        for (ll j = 0; j < n; j++) {
            tmp[j] = 0;
            for (ll k = 0; k < n; k++) {
                tmp[j] = (add(tmp[j], mul(a.mat[i][k], b.mat[k][j])));
            }
            tmp[j] %= M;
        }
        res.mat.push_back(tmp);
    }
    return res;
}

matrix powMat(matrix a, ll b, ll p){
    matrix res; ll n = a.mat[0].size();
    for (ll i = 0; i < n; i++) {
        vl tmp;
        for (ll j = 0; j < n; j++) {
            tmp.push_back(i == j);
        }
        res.mat.push_back(tmp);
    }

    while (b > 0){
        if (b & 1) res = multi(res, a);
        a = multi(a, a);
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n, k; cin >> n >> k;
    matrix m;
    for (ll i = 0; i < n; i++) {
        vl tmp;
        for (ll j = 0; j < n; j++) {
            ll x; cin >> x;
            tmp.push_back(x);
        }
        m.mat.push_back(tmp);
    }
    m = powMat(m, k, M);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cout << m.mat[i][j] % M << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t = 1;
    while (t--) solve();
}