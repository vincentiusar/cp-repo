#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

double r, l, v, theta, alfa, jarakLingkaran, jarakTongkat;

const ld PI = acos((long double) 0)*2;

int main (){
	
	cin >> theta >> r >> v >> l;
	
	alfa = theta / 2;
	
	jarakLingkaran = r / tan(alfa*PI/180);
	jarakTongkat = l / tan(theta*PI/180);
	
	jarakLingkaran = max(jarakLingkaran, jarakTongkat + r);
	
	cout << fixed << setprecision(2) << (100-jarakLingkaran)/v << endl;
	
}
