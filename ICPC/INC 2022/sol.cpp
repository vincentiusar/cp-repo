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
typedef pair<string, ll> psl;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

bool cmp(__int128 x, __int128 y) { return x > y; }

using lll = __int128;


void solve() {
    ll n, k; cin >> n >> k;
    
    vector<vector<psl>> m(n);
    for (ll i = 0; i < n; i++) {
        psl op1; cin >> op1.first >> op1.second;
        psl op2; cin >> op2.first >> op2.second;

        if (op1.first == "+" && op2.first == "x") 
            swap(op1, op2);
            
        m[i].push_back(op1);
        m[i].push_back(op2);

        if (op1.first == "x" && op1.second == 0) {
            m.clear();
            k = 0;
        }
        if (op2.first == "x" && op2.second == 0) {
            m.clear();
            k = 0;
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = i+1; j < n; j++) {
            for (ll q = 0; q < 2; q++) {
                if (m[i][q].first == "x" && m[i][q].second < 0 && m[j][q].first == "x" && m[j][q].second < 0) {
                    m[i][q].second *= -1;
                    m[j][q].second *= -1;
                }
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 2; j++) {
            cout << m[i][j].first << " " << m[i][j].second << " ";
        }
        cout << endl;
    }
    

    // lll highest = __uint128_t(__int128_t(-1L));
    ll highest = 0;
    for (ll i = 0; i < n; i++) {
        ll first;
        if (m[i][0].first == "+") {
            first = k + m[i][0].second;
        } else {
            first = k * m[i][0].second;
        }

        ll second;
        if (m[i][1].first == "+") {
            second = k + m[i][1].second;
        } else {
            second = k * m[i][1].second;
        }

        cout << first << " " << second << endl;
        cout << (first > second ? "kiri" : "kanan") << endl;
        highest = max(first, second);
        k = highest;
    }

    cout << (highest) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}
