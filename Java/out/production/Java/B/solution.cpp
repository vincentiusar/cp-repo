#include <iostream>

using namespace std;

int main() {
    int X, D, A;
    // kunci solusi salah (lupa diinit)
    // int p4, p3;
    int p4 = 0, p3 = 0;

    cin >> X >> D >> A;

    p4 = D / 4;
    D %= 4;

    if (D > 0) {
        if (A + D >= 4) {
            ++p4;
            A -= 4 - D;
            D = 0;
        } else if (A + D >= 3) {
            ++p3;
            A -= 3 - D;
            D = 0;
        }
    }

    // note: ada kasus jika A, D, dan X pada akhir perhitungan ganjil (1111 1 1), akan mendapat hasil output koma.
    // Tidak disebutkan secara implisit bahwa total harga yang dibayar dibulatkan ke bawah (jika koma) atau tidak
    // cout << (int)(((2 * (p4 + p3)) + (0.5 * A) + D) * X) << endl;
    cout << (((2 * (p4 + p3)) + (0.5 * A) + D) * X) << endl;
}