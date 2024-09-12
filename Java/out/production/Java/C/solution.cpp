#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-4;

int main() {
    int N;
    double X, Y, Z;

    cin >> N >> X >> Y >> Z;
    double need = (N - 1) * 2 * sqrt((X * X) + (Y * Y)) + X;
    if (need - Z < EPS) {
        cout << "Bisa" << endl;
    } else {
        cout << "Tidak Bisa" << endl;
    }
}