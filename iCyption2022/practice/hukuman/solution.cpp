#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);  
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int modus = 0;
    vector<int> leftModus(n,0);
    vector<int> left(10,0);
    for(int i = 0; i < n; i++){
        left[arr[i]]++;
        if(left[arr[i]] > left[modus]){
            modus = arr[i];
        }else if(left[arr[i]] == left[modus]){
            modus = min(modus,arr[i]);
        }
        leftModus[i] = modus;
    }

    modus = 0;
    vector<int> rightModus(n,0);
    vector<int> right(10,0);
    for(int i = n-1; i > -1; i--){
        right[arr[i]]++;
        if(right[arr[i]] > right[modus]){
            modus = arr[i];
        }else if(right[arr[i]] == right[modus]){
            modus = min(modus,arr[i]);
        }
        rightModus[i] = modus;
    }

    int q;
    string ans = "";
    cin >> q;
    for(int i = 0; i <q;i++){
        char chain;
        int x;
        cin >> chain >> x;
        if(chain == 'L'){
            ans += to_string(leftModus[x-1]) +"\n";
        }else{
            ans += to_string(rightModus[n-x]) +"\n";
        }
    }
    cout << ans << endl;
    return 0;
}