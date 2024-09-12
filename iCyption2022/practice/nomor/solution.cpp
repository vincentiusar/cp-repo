#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll M = 1e9 + 7;

ull gcd(ull a, ull b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ull checklcm(ull a, ull b) {
    ull Max = max(a, b), Min = min(a, b);
    ull P = Max / gcd(a, b);
    ull PowP = log10(P), PowMin = log10(Min);

    if (PowP + PowMin > 19) 
        return 0;
    return P * Min;
}

ull countDiv(ull Min, ull Max, ull N) {
    if (Min % N == 0) 
        return Max / N - Min / N + 1;
    return Max / N - Min / N;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ull Min, Max, A, B; cin >> Min >> Max >> A >> B;

    ull DivByA = countDiv(Min, Max, A), DivByB = countDiv(Min,Max,B);
    
    ull DivByAB = 0;
    if (checklcm(A,B) > 0) {
        DivByAB = countDiv(Min,Max,checklcm(A,B));
    } else if (checklcm(A, B) == 0 && Min == 0) {
        DivByAB = 1;
    } else {
        DivByAB = 0;
    }
    cout << DivByA + DivByB - 2 * DivByAB << endl;
}