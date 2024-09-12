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

void solve() {
    ll n; cin >> n;
    
    string str; cin >> str;
    if (n == 1) { cout << 0 << endl; return; }
    
    vl R, L;
    ll total = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'L' && i < n/2 && n % 2 == 1) L.push_back(i);
        else if (str[i] == 'L' && i < n/2 && n % 2 == 0) L.push_back(i);
        else if (str[i] == 'R' && i >= n/2 && n % 2 == 1) R.push_back(i);
        else if (str[i] == 'R' && i >= n/2 && n % 2 == 0) R.push_back(i);

        if (str[i] == 'L') {
            total += i;
        } else {
            total = total + n-i-1;
        }
    }

    ll fr = 0;
    for (int i = 0; i < n; i++) {
        if (R.size() == 0 && fr != L.size()) {
            total += (n - L[fr] - 1) - L[fr];
            fr++;
            // cout << total << " " <<  fr << " " << L.size() << endl;
        } else if (R.size() != 0 && fr == L.size()) {
            total += R[R.size()-1] - (n - R[R.size()-1] - 1);
            R.pop_back();
            // cout << total << " " <<  fr << " " << L.size() << endl;
        }
        if (fr != L.size() && R.size() != 0) {
            if (n - L[fr] - 1 >= R[R.size()-1] && fr != L.size()) {
                // cout << "L " << L[fr] << endl;
                total += (n - L[fr] - 1) - L[fr];
                fr++;
            } else if (n - L[fr] - 1 < R[R.size()-1] && R.size() != 0 ) {
                // cout << "R " << R[R.size()-1] << endl;
                total += R[R.size()-1] - (n - R[R.size()-1] - 1);
                R.pop_back();
            }
        }
        cout << total << " ";
    }

    cout << endl;
}

int main() {
    ll t;
    // t = 1;
    cin >> t;
    while (t--) solve();
}