#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

LL sum(LL a,LL b){
	if ((((a % 2 != 0) && (b % 2 == 0)) || ((a % 2 == 0) && (b % 2 != 0)))){
		LL c = a+b;
		LL d = (b-a+1)/2;
		return c*d;
	}
	else{
		LL c = (a+b)/2;
		LL d = (b-a+1);
		return c*d;
	}
}

LL summatrix(LL i1, LL j1, LL i2, LL j2){
	return (j2 - j1 + 1)*sum(i1,i2) + (i2 - i1 + 1)*sum(j1,j2);
}

int main(){
	LL i1,j1,i2,j2,m,n;
	cin >> m >> n;
	cin >> i1 >> j1 >> i2 >> j2;
	LL ans = summatrix(i1,j1,i2,j2);
	cout << ans;
}
