#include <bits/stdc++.h>

using namespace std;

//#define ull unsigned long long
//const ull M = 1e9 + 7;

int main() {
    string eko, ganesh;
    getline(cin, eko); getline(cin, ganesh);

    int delta = 0;

    for (int i = 0; i < eko.length(); i++) {
        if ((eko[i] == 'h' && ganesh[i] == 'a') || (eko[i] == 'a' && ganesh[i] == 'e') || (eko[i] == 'e' && ganesh[i] == 'h')) {
            delta++;
        } else if (eko[i] != ganesh[i]) {
            delta--;
        }
    }

    if (delta == 0) { cout << "Draw" << endl; return 0; }
    if (delta > 0) { cout << "Eko wins" << endl; }
    else { cout << "Ganesh wins" << endl; }
}