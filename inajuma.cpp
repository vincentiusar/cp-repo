#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
const int MAX_N = 20;

int grid[MAX_N][MAX_N];
int n, cnt = 0, zeros = 0;

bool in(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n; }

// backtrack

bool check(int i, int j) {
    if (cnt == zeros) {
        return true;
    } else {
        for (int k = 0; k < 4; k++) {
            int x = i+dx[k], y = j+dy[k];

            if (in(x,y) && grid[x][y] == 0) {
                cnt++;
                grid[x][y] = 1;
                if (check(x,y)) return true;
                cnt--;
                grid[x][y] = 0;
            }
        }
    }
    return false;
}

void solve() {
    int x, y;
    cin >> n >> x >> y;
    x--, y--;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j], zeros += (grid[i][j] == 0);

    cout << (check(x, y) ? "primogems +10" : "makan paymon");
}
 
int main() {
    solve();
}
