#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;

void solve() {
  int n;
  cin >> n;
  int arr[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      cin >> arr[i][j];

  vvb reachable(n, vb(n, false));

  reachable[0][0] = true;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j <= i; j++) {
      if (reachable[i][j]) {
        if (arr[i][j] >= arr[i+1][j])
          reachable[i+1][j] = true;
        if (arr[i][j] >= arr[i+1][j+1])
          reachable[i+1][j+1] = true;
      }
    }
  }

  bool bisa = false;
  for (int j = 0; j < n; j++)
    if (reachable[n-1][j])
      bisa = true;

  cout << (bisa ? "BISA" : "MUSTAHIL") << '\n';
}
 
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  solve();
}