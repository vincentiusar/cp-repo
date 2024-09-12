#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    string s, t; cin >> s >> t;
    
    if (s.length() < t.length()) swap(s, t);
    if (s.length() > t.length() && s.find(t) != string::npos) {
        cout << s.length();
    } else {
        if (s == t) {
            cout << s.length();
        } else {
            ll longest = s.length();
            ll right = t.length()-1;
            ll total = 0;
            for (ll i = t.length()-1; i >= 0; i--) {
                //cout << s[i] << " " << t[right] << endl;
                if (s[i] != t[right]) total = 0, right = t.length()-1;
                else right--, total++;
                longest++;
            }
            ll left = 0, record = longest - total;
            total = 0, longest = s.length();
            for (ll i = 0; i < t.length(); i++) {
                //cout << s[s.length() - t.length() + i] << " " << t[left] << endl;
                if (t[left] != s[s.length() - t.length() + i]) total = 0, left = 0;
                else left++, total++;
                longest++;
            }
            longest = longest - total;
            if (longest < record) record = longest;
            cout << record;
        }
    }
    cout << endl;
}