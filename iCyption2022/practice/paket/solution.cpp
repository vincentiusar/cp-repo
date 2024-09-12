#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll A, B, N; cin >> A >> B >> N;

    ll maxs = max(A, B), mins = min(A, B);
    ll numMax = N / maxs;
    while ((N - maxs * numMax) % mins != 0 && numMax > 0) {
        numMax--;
    }

    ll numMin = (N - maxs * numMax) / mins;
    if (maxs * numMax + mins * numMin == N) {
        if (maxs == A && mins == B) {
            cout << numMax << " " << numMin << endl;
            return 0;
        } else {
            cout << numMin << " " << numMax << endl;
            return 0;
        }
    }
    cout << "Pesan Ulang" << endl;
}