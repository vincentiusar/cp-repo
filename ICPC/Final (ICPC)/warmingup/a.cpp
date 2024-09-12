#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pl;

void solve() {
	ll n; cin >> n;
	pl arr;
	ld mini = LONG_LONG_MAX, maxi = LONG_LONG_MIN, total = 0;
	for (ll i = 0; i < n; i++) {
		cin >> arr.first >> arr.second;
		ld ratio = 0;
		ratio = arr.first / arr.second;
		if (ratio < mini) mini = ratio;
		if (ratio > maxi) maxi = ratio;
		total += ratio;
	}
	cout << fixed << setprecision(11) << mini << " " << maxi << " " << total;
}

int main() {
	ll t; 
	//cin >> t;
	t = 1;
	while (t--) solve();
}