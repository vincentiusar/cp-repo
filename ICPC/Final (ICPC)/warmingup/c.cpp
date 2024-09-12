#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
	ll n; cin >> n;
	
	ll countOne = 0, tmpZero = 0, countZero = 0;
	ll first = 0, second = 0;

	for (ll i = 1; i < n; i++) {
		ll x; cin >> x;
		if (i == 1 && x == 1) first = 1;
		if (i == 2 && x == 1) second = 1;
		if (n == 3 && first == 0 && second == 1) {
			cout << 1 << endl;
			return;
		}
		if (x == 1) countOne++;
		if (x == 0) tmpZero++, countZero++;
		if (i != 1 && x == 1) tmpZero = 1;
	}
	
	if (countOne == (n - 1)) {
		cout << 1 << endl;
		return;
	} else if (countZero == n - 1) {
		cout << n - 1 << endl;
		return;
	}
	if (tmpZero == 1) {
		cout << 1 << endl;
		return;
	}
	if (tmpZero == 2) {
		cout << 2 << endl;
		return;
	}
	if (first == 1) cout << tmpZero << endl;
	else cout << tmpZero - 1 << endl;
}

int main() {
	ll t; 
	//cin >> t;
	t = 1;
	while (t--) solve();
}