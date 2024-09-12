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

int dp[501][250002/2];
ll arr[501];
ll sum;

bool can(int n, ll m) {
    // db(m);
    if (m == 0)
        return true;
    if (n <= 0 || m < 0)
        return false;
    if (dp[n][m] != -1)
        return dp[n][m];
    
    dp[n][m] = can(n-1, m - arr[n]) + can(n-1, m);
    if (arr[n] == 2)
        dp[n][m] += can(n-1, m-1);
    return dp[n][m] != 0;
}

void ans() {

    for (int i = 0; i <= 500; i++)
        for (int j = 0; j <= 250000/2; j++)
            dp[i][j] = -1;

    int n; cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i+1];
        sum += arr[i+1];
    }

    if (sum % 2) {
        cout << "NO\n"; return;
    }

    sum /= 2;
    cout << (can(n, sum) ? "YES" : "NO") << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) ans();
}