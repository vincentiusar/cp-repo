#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long

ull gcd(ull a, ull b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ull lcm(ull a, ull b) {
    return a * b / gcd(a, b);
}

int main() {
    ull a, b; cin >> a >> b;

    cout << lcm(a, b) << endl;
}