#include <bits/stdc++.h>

using namespace std;

int main() {
	string str; cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '7' && str[i] != '4') {
			cout << "NO";
		}
	}
	cout << "YES";
}