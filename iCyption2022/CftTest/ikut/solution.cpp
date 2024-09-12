#include <iostream>

using namespace std;

struct peserta {
    string nama;
    int jmlSoal;
};

int main() {
    int a, b;
    cin >> a;
    peserta p[100];
    for (int i=0; i<a; ++i) {
        cin >> p[i].nama >> p[i].jmlSoal;
    }
    cin >> b;

    int min = 101;
    string guru;
    for (int i=0; i<a; ++i) {
        if (p[i].jmlSoal<min && p[i].jmlSoal>=b) {
            guru = p[i].nama;
            min = p[i].jmlSoal;
        }
    }

    if (min==101) {
        cout << "Tidak bisa berguru";
    } else {
        cout << guru;
    }

    return 0;
}
