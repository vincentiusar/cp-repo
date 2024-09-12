#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

bool cmp(__int128 x, __int128 y) { return x > y; }

using lll = __int128;

bool checkPerfectSquare(lll a) {
    lll L = 1, R = a;

    while (L <= R) {
        lll mid = L + (R - L)/2;
        lll sqr = mid * mid;

        if (sqr == a) {
            return true;
        } else if (sqr < a) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return false;
}

int main() {
    lll K = read(), L = read();

    if (K % 2 != 0) { cout << "MUSTAHIL" << endl; return 0; }

    lll S = K / 2;
    lll discriminant = S*S - 4*L;

    if (discriminant < 0) { cout << "MUSTAHIL" << endl; return 0; }

    if (!checkPerfectSquare(discriminant)) { cout << "MUSTAHIL" << endl; return 0; }

    lll rdisc = sqrt(discriminant);
    if ((S + rdisc) % 2 != 0) {
        cout << "MUSTAHIL" << endl; return 0;
    } else {
        cout << "MUNGKIN" << endl; return 0;
    }
}