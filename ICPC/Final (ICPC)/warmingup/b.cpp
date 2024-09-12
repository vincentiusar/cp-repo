#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
	ll n; cin >> n;
	for (ll i = 0; i < n; i++) {
		ll x; cin >> x;
		cout << n - x + 1 << " ";
	}
	cout << endl;
}

int main() {
	ll t; 
	//cin >> t;
	t = 1;
	while (t--) solve();
}