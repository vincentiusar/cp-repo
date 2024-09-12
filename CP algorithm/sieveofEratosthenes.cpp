#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 1e9 + 7;
const ll MAX = 1e6;

bool prime[MAX];

void SieveOfEratosthenes() {
    ll n = 49;
    memset(prime, true, sizeof(prime));
    for (ll p = 2; p * p <= sqrt(n); p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= sqrt(n); i += p)
                prime[i] = false;
        }
    }

    for (ll p = 2; p <= sqrt(n); p++)
        if (prime[p])
            cout << p << " ";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    SieveOfEratosthenes();
    return 0;
}