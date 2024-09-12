#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string orang = "";
    ld best = -1;
    bool seri = 0;
    ll t; cin >> t;
    while (t--) {
        string str; cin >> str;
        
        ld n, k; cin >> n >> k;
        ld luas, luasDalam;
        if (n == 3) {
            luas = n*k*k, luasDalam = k*k*0.5*n;
        } else {
            luas = n*k*k, luasDalam = k*k;
        }
        
        ld luasLuar = ld(luas - luasDalam);
        ld selisih = ld(luasLuar-luasDalam);
        if (best < selisih) {
            best = selisih;
            orang = str;
            seri = 0;
        } else if (best == selisih) {
            seri = 1;
        }
    }
    if (seri) cout << "SERI";
    else cout << orang << endl;
}