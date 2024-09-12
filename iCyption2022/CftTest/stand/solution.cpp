#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int harga[n];
  for (int i = 0; i < n; i++) {
    cin >> harga[i];
  }
  int totalsewa[n];
  totalsewa[0]=0;
  if (n>0) {
    totalsewa[1]=harga[0];
    for (int i = 2; i < n+1; i++){
      totalsewa[i] = max(totalsewa[i-1],harga[i-1]+totalsewa[i-2]);
    }
  }
  cout << totalsewa[n] << endl;
}
