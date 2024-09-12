#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N; cin >> N;

    vector<int> data;

    for (int i = 0; i < N; i++){
        int x; cin >> x;
        data.push_back(x);
    }
    sort(data.begin(),data.end(), cmp);

    int i = 0;
    while (data[i] == data[0]){
        i++;
    }
    cout << data[0] << " " << i << endl;
}