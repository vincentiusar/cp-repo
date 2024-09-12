#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main() {
    ll N, L, R;
    cin >> N >> L >> R;

    ll a[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a, a + N);

    ll total = 0;
    for (int i = 0; i < N; i++) {
        int lowerBound = -1, upperBound = -1;

        int l = i+1, r = N-1;
        while (l <= r) {
            int mid = (l + r)/2;
            if (a[i] * a[mid] >= L)
                lowerBound = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        l = i+1, r = N-1;
        while (l <= r) {
            int mid = (l + r)/2;
            if (a[i] * a[mid] <= R)
                upperBound = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        if (lowerBound != -1 && upperBound != -1)
            total += (upperBound - lowerBound + 1);
    }

    if (total == 0) {
        cout << "0/1" << '\n';
        return 0;
    }

    ll penyebut = N*(N - 1)/2;
    ll fpb = __gcd(total, penyebut);
    total /= fpb, penyebut /= fpb;
    cout << total << '/' << penyebut << '\n';
}