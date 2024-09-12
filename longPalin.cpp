#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

ll palindrom(string kata, int kiri, int kanan) {
    string longest = "";
    int i = kiri, j = kanan;
    while (i < j) {
        if (kata[i] == kata[j]) {
            i++;
            j--;
        } else {
            break;
        }
    }
    if (i >= j) {
        while (kiri <= kanan) {
            longest += kata[kiri];
            kiri++;
        }
    }
    return longest.length();
}

int main() {
    string str; getline(cin, str);
    string res = "";
    for (ll i = 0; i < str.length(); i++) {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            str[i] += 'a' - 'A';
        }
        if (isalpha(str[i])) {
            res += str[i];
        }
    }
    
    ll longest = 0;

    for (ll i = 0; i < res.length() + 1; i++) {
        for (ll j = i+1; j < res.length() + 1; j++) {
            if (longest < palindrom(res, i, j)) longest = palindrom(res, i, j);
        }
    }
    cout << longest;
}