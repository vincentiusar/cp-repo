#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n; cin >> n;
    ll total = 0, num, mins;
    cin >> num;
    mins = num;
    total += num;
    n--;
    while (n--) {
        cin >> num;
        if (mins > num) mins = num;
        total = total + num;
    }
    cout << total - mins + 1 << '\n';
}