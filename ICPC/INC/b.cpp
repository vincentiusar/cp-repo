#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 1e9+7;

bool isSubsetSum(ll set[], ll n, ll sum) {
  
    bool subset[n + 1][sum + 1];
 
    for (ll i = 0; i <= n; i++)
        subset[i][0] = true;

    for (ll i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
 
    return subset[n][sum];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n; cin >> n;
    ll arr[n] = {0};

    ll sum = 0;

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum % 2 == 1) {
        cout << "NO";
        return 0;
    }

    if (isSubsetSum(arr, n, sum/2)) {
        cout << "YES";
    } else {
        sort(arr, arr+n, greater<ll>());
        
        ll total = 0;

        for (ll i = 0; i < n && sum > total; i++) {
            total += arr[i];
            sum -= arr[i];
            if (sum == total) {
                cout << "YES" << endl;
                return 0;
            }
        }

        ll atas = 0, bawah = 0;
        for (ll i = 0; i < n; i++) {
            if (atas < bawah) {
                atas += arr[i];
            } else if (bawah == atas && arr[i] == 2) {
                bawah++; atas++;
            } else {
                bawah += arr[i];
            }
        }
        
        if (atas == bawah) cout << "YES";
        else cout << "NO";
    }
}