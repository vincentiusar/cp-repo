#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector< vector <ll> > vii;
typedef pair<ll, ll> pll;
const ll M = 1e9 + 7;

int visited[30][30] = {0};
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};
int m, n;

bool isInside(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

void solve() {
    cin >> n >> m;

    char arr[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];

    int a, b; cin >> a >> b;
    
    a--, b--;

    queue<pll> q;
    q.push({a, b});
    visited[a][b] = 1;

    int ans = -1;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (arr[x][y] == 'M') {
            ans = visited[x][y];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = x + moveX[i], next_y = y + moveY[i];

            if (!visited[next_x][next_y] && isInside(next_x, next_y) && arr[next_x][next_y] != 'X') {
                q.push({next_x, next_y});
                visited[next_x][next_y] = visited[x][y] + 1;
            }
        }
    }

    if (ans != -1) {
        cout << ans - 1 << endl;
        return;
    }

    cout << "Keknya ga bener deh" << endl;
}

int main() {
    ll t;
    t = 1;
    // cin >> t;
    while (t--) solve();
}