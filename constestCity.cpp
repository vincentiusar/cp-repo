#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector< vector <char> > vii;
typedef pair<ll, ll> pll;
const ll M = 1e9 + 7;

vii g;
queue <pair <int, int>> q;
int moveX[4] = {-1, 1, 0, 0}, moveY[4] = {0, 0, 1, -1};
int n, m;

bool isInside(int x, int y) { return x < n && y < m && x >= 0 && y >= 0 && g[x][y] != '#'; }

void solve() {
    int record[27] = {0};
    bool vis[1000][1000] = {0};
    int perang = 0;
    cin >> n >> m;
    
    g.resize(n+1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            g[i].push_back(x);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool flag = 0;
            if (isalpha(g[i][j]) && !vis[i][j]) {
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int new_x = x + moveX[k], new_y = y + moveY[k];
                        if (isInside(new_x, new_y) && !vis[new_x][new_y]) {
                            q.push({new_x, new_y});
                            if (g[new_x][new_y] != g[i][j] && isalpha(g[new_x][new_y]) && !flag)
                                perang++, flag = 1;
                            vis[new_x][new_y] = 1;
                        }
                    }
                }
                if (!flag) record[int(g[i][j]) - int('a')]++;
            }
        }
    }
    for (int i = 0; i < 27; i++) {
        if (record[i] != 0) {
            cout << char(i + 'a') << " " << record[i] << endl;
        }
    }
    cout << "contested " << perang;

    perang = 0;
    for (int i = 0; i < 27; i++) {
        record[i] = 0;
    }
    for (int i = 0; i <= 101; i++) {
        for (int j = 0; j <= 101; j++) {
            vis[i][j] = 0;
        }
    }
    g.clear();
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t; cin >> t;
    // ll t = 1;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
        if (i != t)
            cout << endl;
    }
}