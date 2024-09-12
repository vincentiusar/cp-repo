#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
int arr[100001] = {0};

void dfs(int node, int prev, int time) {
    arr[node] = time;
    for (int adj : tree[node]) {
        if (adj != prev) {
            dfs(adj, node, time+1);
        }
    }
}

int main() {
    int n; 
    cin >> n;

    int a, b, x; 
    cin >> a >> b >> x;

    tree.resize(n+1);

    for (int i = 1; i <= n-1; i++) {
        int A, B; cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    dfs(x, -1, 0);
    int ruteA = arr[a];
    int ruteB = arr[b];

    dfs(a, -1, 0);
    ruteA += arr[b];
    ruteB += arr[b];

    cout << min(ruteA, ruteB) << '\n';
}