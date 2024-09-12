#include <iostream>

using namespace std;

int mapping[1001][1001];
bool isCheck[1001][1001];

bool IsInMap(int n, int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < n);
}

void FindingRegion(int i, int j, int n){
    // 8 arah
    if(IsInMap(n,i,j)){
        if (mapping[i][j] == 0){
            return;
        }
        if(isCheck[i][j])
            return;
        isCheck[i][j] = true;
        if(mapping[i][j] == 1){
            FindingRegion(i+1,j,n);
            FindingRegion(i-1,j,n);
            FindingRegion(i,j+1,n);
            FindingRegion(i,j-1,n);
            FindingRegion(i+1,j+1,n);
            FindingRegion(i+1,j-1,n);
            FindingRegion(i-1,j+1,n);
            FindingRegion(i-1,j-1,n);
        }
    }
}

int Solve(int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!isCheck[i][j]){
                if(mapping[i][j] == 1){
                    count++;
                    FindingRegion(i,j,n);
                }
            }
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mapping[i][j];
            isCheck[i][j] = false;
        }
    }
    cout << Solve(n) << endl;
    return 0;
}
