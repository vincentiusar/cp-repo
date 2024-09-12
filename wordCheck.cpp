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

int moveX[] = {1, -1, 0, 0, 1, 1, -1, -1}, moveY[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, k;
char arr[101][101];

bool isInside(int i, int j) { return i >= 0 && j >= 0 && i < n && j < k; }

void solve() {
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < k; j++) 
            cin >> arr[i][j];

    string str; cin >> str;
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (arr[i][j] == str[0]) {
                for (int m = 0; m < 8; m++) {
                    string s = ""; s += str[0];
                    int pos = 1;
                    int new_i = i + moveX[m], new_j = j + moveY[m];
                    while (isInside(new_i, new_j) && pos < str.length()) {
                        if (str[pos] == arr[new_i][new_j]) {
                            s += arr[new_i][new_j];
                        } else {
                            break;
                        }
                        pos++;
                        new_i += moveX[m], new_j += moveY[m];
                    }

                    if (s == str) res++;
                }
            }
        }
    }
    if (str.length() == 1) cout << res / 8;
    else cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t; cin >> t;
    // ll t = 1;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
        if (i != t)
            cout << endl;
    }
}