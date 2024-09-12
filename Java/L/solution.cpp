#include <iostream>
using namespace std;

string ask(int x) {
    cout << x << endl;

    string res;
    cin >> res;

    return res;
}

void solve() {
    int l = 1, r = 1e9;
    while (l <= r) {
        int mid = (l + r)/2;
        string ans = ask(mid);
        if (ans == ">") l = mid + 1;
        else if (ans == "<") r = mid - 1;
        else break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
}