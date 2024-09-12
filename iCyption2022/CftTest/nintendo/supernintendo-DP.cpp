#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

LL const MOD = 1e9+9;

LL n, s0, s1, s2, s3, two; 

int main(){
    cin >> n;
    s0 = 0; s1 = 0; s2 = 1; two = 2;
    if (n == 2){
        cout << s2;
    }
    else{
        for (LL i = 3; i <= n; i++){
            s3 = ((s2 + s1) % MOD + two) % MOD;
            two = (two*2LL) % MOD;
            s1 = s2;
            s2 = s3;
            // cout << i << " " << s3 << "\n";
        }
        cout << s3 << "\n";
    }
    return 0;
}
