#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int T;
    ll N, S;
    
    cin >> T;
    
    while (T--) {
        cin >> S >> N;
        ll an = S - (N * N) + N;
        if (an % N == 0 && (an / N) & 1) {
            cout << an / N << " " << (an / N) + 2 * (N - 1) << endl;
        } else {
            cout << "Tidak bisa Nee-chan!" << endl;
        }
    }
    return 0;
}