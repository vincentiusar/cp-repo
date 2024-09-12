#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define pb push_back
#define sz(x) x.size()
#define db(x) cerr << #x << " = " << (x) << endl
#define all(v) (v).begin(), (v).end()
#define rmunique(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void ans() {
    int n; cin >> n;

    bool sesi[n+1] = {false};

    if (n == 1) {
        cout << "? 1 1\n";
        fflush(stdout);
        int res; cin >> res;
        if (res == 1) {
            cout << "! 1 1\n";
        } else {
            cout << "! 0\n";
        }
        return;
    }
    
    bool satu[n+1] = {false}, dua[n+1] = {false};

    for (int i = 1; i <= n; i++) {
        int tanya = 1 ^ i;
        cout << "? 1 " << (i + tanya) << '\n';
        fflush(stdout);
        int res1, res2; cin >> res1;

        tanya = 2 ^ i;
        cout << "? 2 " << (i < 2 ? i - tanya : i + tanya) << '\n';
        fflush(stdout);
        cin >> res2;

        if (res1)   
            satu[i] = true;
        if (res2)
            dua[i] = true;
        
    }

    for (int i = 1; i <= n; i++)
        if (satu[i] && dua[i]) sesi[i] = true;

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (sesi[i]) cnt++;

    if (cnt == 0) {
        cout << "! 0\n"; return;
    }

    cout << "! " << cnt;
    for (int i = 1; i <= n; i++) {
        if (sesi[i]) cout << " " << i;
    }
    cout << '\n';
}
 
int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) ans();
}