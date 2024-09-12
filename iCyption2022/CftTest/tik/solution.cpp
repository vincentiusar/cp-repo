#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define outp(x) cout << #x << " -> " << (x) << endl
#define int long long
#define pii pair<int, int>
#define debug cout << "Masuk" << endl
#define piii pair<pii, pii>

const int N = 1e3;
bool pake[N + 5];
int n, p[N + 5], d[N + 5], dp[N + 5][N + 5];


signed main (){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> d[i];
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++){
		dp[1][i] = p[i];
	}
	for (int i = 2; i <= n; i++){
		vector<vector<int>> seg;
		vector<int> v;
		for (int j = 1; j <= n; j++){
			if (pake[j]){
				if (v.size()){
					seg.push_back(v);
				}
				v.clear();
			}
			else {
				v.push_back(j);
			}
		}
		if (v.size() && v.back() == n && seg.size() && seg[0][0] == 1){
			for (auto j : v){
				seg[0].push_back(j);
			}
		}
		if (seg.empty()){
			seg.push_back(v);
		}
		pake[d[i - 1]] = 1;
		for (auto a : seg){
			int maks = 0;
			for (auto j : a){
				if (dp[i - 1][j] == -1){
					continue;
				}
				maks = max(maks, dp[i - 1][j]);
			}
			for (auto j : a){
				if (pake[j]){
					continue;
				}
				dp[i][j] = p[j] + maks;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			ans = max(dp[i][j], ans);
		}
	}
	cout << ans << endl;
}
