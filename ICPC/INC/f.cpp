#include <bits/stdc++.h>
using namespace std;

bool pal(string x){
    string y = x;
    reverse(y.begin(),y.end());
    if(x==y){
        return true;
    }
    return false;
}

int main(){
    int id = 0;
    int byk = 0;
    string k;
    string m = "";
    string s = "";
    cin>>k;
    if(k.length()==2){
        cout<<k[0]<<" "<<k[1]<<endl;
        return 0;
    }
    else {
        for (int i = 1; i < k.length(); i++) {
            m = k.substr(0, i);
            s = k.substr(i, k.length()-i);
            if (pal(m) && pal(s)) {
                cout << m << " " << s << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}