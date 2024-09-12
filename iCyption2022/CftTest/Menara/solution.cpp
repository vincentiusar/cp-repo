#include <iostream>

using namespace std;

int main() {
    int n, tinggi, dipakai, tambah;
    cin >> n;
    tinggi = 0;
    dipakai = 0;
    tambah = 2;
    
    while (dipakai <= n) {
        dipakai += tambah;
        tambah += 3;
        ++tinggi;
    }

    cout << --tinggi << " " << n-dipakai+tambah-3;
}