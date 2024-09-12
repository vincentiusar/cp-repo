#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> grid(n, string(n, ' '));
    for (int i = 0; i < n; i++) grid[i][0] = '*';
    for (int i = 0; i < n; i++) grid[0][i] = '*';
    for (int i = 0; i < n; i++) grid[i][n-1] = '*';
    for (int i = 0; i < n; i++) grid[n-1][i] = '*';
    for (int i = 0; i < n; i++) grid[i][i] = '*';
    for (int i = 0; i < n; i++) grid[i][n-i-1] = '*';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
            if (j == n-1) cout << '\n';
        }
    }
}