#include <bits/stdc++.h>

using namespace std;

string add(string str1, string str2) {
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    string str = "";
 
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
 
    int carry = 0;
 
    for (int i=n1-1; i>=0; i--) {
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    for (int i=n2-n1-1; i>=0; i--) {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    if (carry)
        str.push_back(carry+'0');
 
    reverse(str.begin(), str.end());
 
    return str;
}

bool isPrime(int n) {
    if (n == 1) return 0;

    for (int i = 2; i * i <= n; i++) 
        if (n % i == 0)
            return 0;

    return 1;
}

int sumOf(string str) {
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        sum += (str[i] - '0');
    }
    return sum;
}

int main() {
    string n, m; cin >> n >> m;

    string sum = "0";

    for (string i = n; i != add(m, "1"); i = add(i, "1")) 
        if (isPrime(sumOf(i))) sum = add(i, sum);

    cout << sum << endl;
}