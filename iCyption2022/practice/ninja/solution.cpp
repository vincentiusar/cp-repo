#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll N, A; cin >> N >> A;

    ll arr[N];
    for (ll i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    ll ans = 0, minReq = 0;
    for (ll i = 0; i < N; i++) {
        minReq = max(minReq + arr[i], 2 * arr[i]);
        if (minReq <= A) {
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;
}