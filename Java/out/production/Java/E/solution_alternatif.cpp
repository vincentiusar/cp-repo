#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

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

int main() {
    lll a;
    a = read();

    if (a > 4) {
        print(a-2);
    } else {
        cout << "-1" << endl;
    }
}