#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
vector < pair < string, long long > > tree;

long long maxLevel = 57;

struct counter{
	long long r, e, c, u, s, i, v;
};

void addCounter(counter *a, counter b){
	a -> r += b.r;
	a -> e += b.e;
	a -> c += b.c;
	a -> u += b.u;
	a -> s += b.s;
	a -> i += b.i;
	a -> v += b.v;
}
void subCounter(counter *a, counter b){
	a -> r -= b.r;
	a -> e -= b.e;
	a -> c -= b.c;
	a -> u -= b.u;
	a -> s -= b.s;
	a -> i -= b.i;
	a -> v -= b.v;
}
long long countLength(long long K){
	long long x = pow(2, K);
	return (long long)(9*x + 7*(x - 1));
}

long long findMaxK(long long R){
	for (long long i = 0; i <= maxLevel; i++){
		if (countLength(i) > R){
			return i - 1;
		}
	}
}

counter blank={0,0,0,0,0,0,0};

long long R;

counter sisa (long long x){
	counter ans = blank;
	for (long long i = 1; i <= x; i++){
		if (i == 1 || i == 5) ans.r++;
		if (i == 2 || i == 9) ans.e++;
		if (i == 3) ans.c++;
		if (i == 4) ans.u++;
		if (i == 6) ans.s++;
		if (i == 7) ans.i++;
		if (i == 8) ans.v++;
	}
	return ans;
}

//A = "RECURSIVE", B = "ECU", C = "SIVE"
counter A = {2,2,1,1,1,1,1}, B = {0,1,1,1,0,0,0}, C = {0,1,0,0,1,1,1};

counter kali(counter a, long long x){
	a.r *= x;
	a.e *= x;
	a.c *= x;
	a.u *= x;
	a.s *= x;
	a.i *= x;
	a.v *= x;
	return a;
}

void printCounter(counter ans){
	cout << "c: " << ans.c << endl;
	cout << "e: " << ans.e << endl;
	cout << "i: " << ans.i << endl;
	cout << "r: " << ans.r << endl;
	cout << "s: " << ans.s << endl;
	cout << "u: " << ans.u << endl;
	cout << "v: " << ans.v << endl;
}

counter countABC(long long K) {
	long long x = pow(2, K);
	counter ans = blank;
	addCounter(&ans, kali(A, x));
	addCounter(&ans, kali(B, x-1));
	addCounter(&ans, kali(C, x-1));
	return ans;
}

long long KInput, Left, Right;

counter countRecursive(long long R){
	vector < long long > K;
	long long ecu = 0, sive = 0;
	counter ans = blank;
	while (R > 9) {
		long long maxNow = findMaxK(R);
		K.pb(maxNow);
		R -= countLength(maxNow);
		if (K[K.size()-1] == K[K.size()-2]){
			if (R < 4){
				if (R >= 1) ans.s++;
				if (R >= 2) ans.i++;
				if (R >= 3) ans.v++;
				R = 0;
				break;
			}
			else {
				sive++;
				R-=4;
			}
		}
		if (R < 3) {
			if (R >= 1) ans.e++;
			if (R >= 2) ans.c++;
			R = 0;
			break;
		}
		R -= 3;
		ecu++;	
	}
	for (long long i = 0; i < K.size(); i++){
		addCounter(&ans, countABC(K[i]));
	}
	addCounter(&ans, kali(B, ecu));
	addCounter(&ans,sisa(R));
	return ans;
}

int main (){
	cin >> KInput >> Left >> Right;
	maxLevel = min(maxLevel, KInput);
	counter Left_ = countRecursive(Left - 1);
	
	counter Right_ = countRecursive(Right);
	
	subCounter(&Right_, Left_);
	printCounter(Right_);
}
