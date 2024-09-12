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

int n, m;
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

vii g;
vector < vector < pair <ll, ll> > > adj;
int vis[1000][1000];

bool isInside(int x, int y) { return x >= 0 && y >= 0 && x < m && y < n; }

void solve() {
    cin >> m >> n;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 10000;
        }
    }
    vis[0][0] = 0;

    g.resize(m+1);
    adj.resize(m*n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            g[i].push_back(x);
            if (x != 0) {
                adj[x].push_back({i, j});
            }
        }
    }

    if (n == 1 && m == 1) { cout << 0 << endl; return; }
    if (g[0][0] == g[m-1][n-1] && g[0][0] != 0) { cout << 0 << endl; return; }

    queue <pair <int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int x = q.front().first; int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = x + moveX[i], new_y = y + moveY[i];
            if (isInside(new_x, new_y) && vis[new_x][new_y] == 10000) {
                if (g[new_x][new_y] == 0) {
                    q.push({new_x, new_y});
                    vis[new_x][new_y] = min(vis[x][y]+1, vis[new_x][new_y]);
                } else {
                    int value = g[new_x][new_y];
                    for (int k = 0; k < adj[value].size(); k++) {
                        q.push(adj[value][k]);
                        vis[adj[value][k].first][adj[value][k].second] = vis[x][y]+1;
                    }
                    vis[new_x][new_y] = min(vis[x][y]+1, vis[new_x][new_y]);
                }
            }
        }
    }

    cout << vis[m-1][n-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // ll t; cin >> t;
    ll t = 1;
    while (t--) solve();
}