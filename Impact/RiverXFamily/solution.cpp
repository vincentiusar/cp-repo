#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull n; cin >> n;
    ull arr[n] = {0};

    for (ull i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    if (n == 1) { cout << arr[0]; return 0; }
    if (n == 2) { cout << max(arr[0], arr[1]); return 0; }

    ull first = arr[0], second = arr[1];
    // ull total = accumulate(arr, arr+n, 0);
    ull sum = 0;
    n--;

    while (n > 1) {
        ull tmp = 0;
        tmp += max(first, second);      // 2 orang terbaik pertama nyebrang
        tmp += first;                   // orang terbaik nyebrang balik
        tmp += max(arr[n], arr[n-1]);   // 2 orang terlambat nyebrang

        if (n - 1 != 1) tmp += second;  // kalau masih ada sisa orang belum nyebrang, si orang terbaik ke 2 nyebrang
        // cout << tmp << " " << first + arr[n];
        if (tmp < arr[n] + arr[n-1] + 2 * first) {
            sum += tmp;
            // cout << "sono" << endl;
            n -= 2;                         // kurangi 2 orang yang nyebrang barusan
        } else {
            // cout << "sini" << endl;
            sum += first + arr[n];
            n--;
        } 
    }
    if (n == 1) sum += max(arr[0], arr[1]);     // kalau masih ada sisa orang yang belum nyebrang (pasti 2 orang terbaik) maka sebrangin. untuk kasus n genap

    cout << sum << endl;
}