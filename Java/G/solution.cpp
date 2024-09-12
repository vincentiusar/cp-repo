#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

bool checkPerfectSquare(ull a) {
    ull L = 1, R = a;
    while (L <= R) {
        ull mid = L + (R - L)/2;
        ull sqr = mid * mid;
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
    ull K, L; cin >> K >> L;

    if (K % 2 != 0) { cout << "MUSTAHIL" << endl; return 0; }

    ull S = K / 2;
    ull discriminant = S*S - 4*L;

    if (discriminant < 0) { cout << "MUSTAHIL" << endl; return 0; }

    if (!checkPerfectSqrt(discriminant)) { cout << "MUSTAHIL" << endl; return 0; }

    ull rdisc = sqrt(discriminant);
    if ((S + rdisc) % 2 != 0) {
        cout << "MUSTAHIL" << endl; return 0;
    } else {
        cout << "MUNGKIN" << endl; return 0;
    }
}