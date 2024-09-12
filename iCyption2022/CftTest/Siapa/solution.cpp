#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s1) {
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    if(s1==s2) return true;
    return false;
}

int main() {
    string s;
    int a=0, b=0, n;
    cin >> n;

    for(int i=1; i<=n; ++i) {
        cin >> s;
        if (isPalindrome(s)) {
            if (i%2 == 1) ++a;
            else ++b;
        }
    }

    if(a>b) cout << "Andi menang";
    else if (a<b) cout << "Budi menang";
    else cout << "Gaada yang menang";
}