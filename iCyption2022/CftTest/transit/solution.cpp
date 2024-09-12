#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define fi first
#define se second

void solve() {
    int n, m;
    cin >> n >> m;
    vvi g(n);
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y, x--, y--;
        g[x].push_back(y);
    }
    int src, target;
    cin >> src >> target, src--, target--;

    queue<pii> q;
    bool vis[n] = {0};
    q.push({src, 0});
    vis[src] = true;
    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();

        if (cur == target) {
            cout << dist - 1 << '\n';
            return;
        }

        for (int& adj : g[cur]) {
            if (!vis[adj]) {
                q.push({adj, dist + 1});
                vis[adj] = true;
            }
        }
    }
    cout << -1 << '\n';
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}
