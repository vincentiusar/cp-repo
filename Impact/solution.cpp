#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, k; cin >> n >> k;
    ll arr[n+1];

    for (ll i = 0; i < n; i++) cin >> arr[i+1];

    ll mini = 0;
    for (ll i = 1; i <= k; i++)
        mini += arr[i];

    ll mini_copy = mini;
    for (ll i = k+1; i <= n; i++) {
        mini_copy -= arr[i - k];
        mini_copy += arr[i];

        mini = min(mini, mini_copy);
    }

    cout << mini << endl;
}