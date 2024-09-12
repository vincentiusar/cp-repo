#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    ofstream out("ouput.txt");

    int x = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == x || j == n-x+1 || i == 1 || i == n) {
                out << "* ";
            } else {
                out << "  ";
            }
        }
        if (i <= n/2) x++;
        else x--;
        out << endl;
    }
}