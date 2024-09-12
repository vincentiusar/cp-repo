#include <bits/stdc++.h>

using namespace std;

#define init ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

int main() {
    ll n, m; cin >> n >> m;
    char x;
    ll size = n * m;
    ll ix = 1, jx = 1, io = 1, jo = 3;
    if (m == 2) jx = 1, jo = 2;
    while (size--) {
        if (m == 2) {
            cin >> x;
            if (x == 'X') {
                cout << ix << " " << jx << endl;
                if (ix % 2 == 0) jx = 1;
                else jx++;
                ix++;
            } else {
                cout << io << " " << jo << endl;
                if (io % 2 == 1) jo = 1;
                else jo++;
                io++;
            }
        } else {
            cin >> x;
            if (x == 'X') {
                cout << ix << " " << jx << endl;
                if (jx % 2 == 0) jx += 3;
                else jx++;
                if (jx > m) {
                    if (ix % 2 == 1) jx = 3;
                    else jx = 1;
                    ix++;
                }
            } else {
                cout << io << " " << jo << endl;
                if (jo % 2 == 0) jo += 3;
                else jo++;
                if (jo > m) {
                    if (io % 2 == 1) jo = 1;
                    else jo = 3;
                    io++;
                }
            }
        }
        
        fflush(stdout);
    }
}