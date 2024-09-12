#include<iostream>
using namespace std;

// inti dari persyaratan pada soal
// misalkan kita punya array sebesar N = [1, 2, 3, ..., N]
// kita harus:
// 1. Pindahkan setiap elemen agar a[i] != i
// 2. Perpindahan bilangan ganjil harus ke posisi ganjil, dan perpindahan
//    genap harus ke posisi genap.

int main() {
  int N;
  cin >> N;

  if (N <= 3) {
    cout << -1 << '\n';
    return 0;
  }

  int ans[N] = {0};
  for (int i = 0; i < N; i++)
    ans[i] = i + 1;
  for (int i = 0; i < N - 2; i++)
    swap(ans[i], ans[i + 2]);

  for (int i = 0; i < N; i++)
    cout << ans[i] << " \n"[i == N-1];
}
