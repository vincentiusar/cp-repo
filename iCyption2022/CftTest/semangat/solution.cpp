#include <bits/stdc++.h>
using namespace std;

int main(){
	string numstring;
	cin >> numstring;
	int n = numstring.length();
	int num[n]; // array of digits
	for (int i = 0; i < n; i++)
		num[i] = numstring[i] - '0';
	int sumdigit = 0;
	sumdigit = accumulate(num,num+n,sumdigit);
	if (num[n-1] != 0 && num[n-1] != 5)
		cout << "Lebih Semangat Lagi";
	else{
		if (sumdigit % 9 == 0)
			cout << "Semangat 45";
		else{
			if (n > 1){
				int sumbutfirst = (sumdigit - num[0])% 9;
				int firstdigitnew = 9 - sumbutfirst;
				cout << "Ayo Semangat 45" << "\n";
				cout << "Digit pertama baru: "<< firstdigitnew;
			}
			else
				cout << "Lebih Semangat Lagi";
		}
	}
	return 0;
}