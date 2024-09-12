#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
vector<vector<int>> g;
vector<int> timeFound;

void dfs(int node, int prev, int timer) {
    timeFound[node] = min(timeFound[node], timer);
    for (int child : g[node]) {
        if (child == prev) continue;
            dfs(child, node, timer + 1);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    g.resize(n), timeFound.assign(n, INF);

    int x, y;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y, x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < k; i++) {
        cin >> x, x--;
        dfs(x, -1, 0);
    }

    int maxo = *max_element(timeFound.begin(), timeFound.end());
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (timeFound[i] == maxo)
            ans.push_back(i + 1);

    cout << ans.size() << '\n';
    for (int x : ans)
        cout << x << ' ';
}