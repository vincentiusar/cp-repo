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
typedef vector<ll> vl;
typedef vector<ll> vll;

template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void ans() {
    int n; ll k; cin >> n >> k;
    int a, b;
    cin >> a;
    vl A(a);
    for (int i = 0; i < a; i++)
        cin >> A[i];
    
    cin >> b;
    vl B(b);
    for (int i = 0; i < b; i++)
        cin >> B[i];

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    vl prefA(a+1), prefB(b+1);
    prefA[0] = 0, prefB[0] = 0;
    prefA[1] = A[0], prefB[1] = B[0];
    for (int i = 2; i <= a; i++)
        prefA[i] = prefA[i-1] + A[i-1];
    for (int i = 2; i <= b; i++)
        prefB[i] = prefB[i-1] + B[i-1];
    
    ll maxi = 0;
    for (ll i = 0; i <= min(n, b); i++)
        maxi = max(maxi, prefB[i] + prefA[min((k-1)*i + k*(n-i), 1LL * a)]);

    cout << maxi << '\n';
} 

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) ans();
}