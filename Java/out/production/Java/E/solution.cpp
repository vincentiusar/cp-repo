#include <iostream>

using namespace std;

string solve(string s){
    if(s.size() == 1){
        int x = s[0] - '0';
        if(x > 4){
            return to_string(x - 2);
        }else{
            return "-1";
        }
    }else{
        string ans = "";
        int substarct = 2;
        int i = s.size()-1;
        for(int i = s.size() - 1; i > -1; i--){
            s[i] = s[i] - substarct;
            if(s[i] < '0'){
                s[i] += 10;
                substarct = 1;
            }else{
                substarct = 0;
            }
            if(i == 0){
                if(s[i] > '0'){
                    ans = s[i] + ans;
                }
            }else{
                ans = s[i] + ans;
            }
        }
        return ans;
    }
}

int main(){
    string n;
    cin >> n;;
    cout << solve(n) << endl;
    return 0;
}