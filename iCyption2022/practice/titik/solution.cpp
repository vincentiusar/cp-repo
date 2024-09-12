#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> positionX(n);
    for(int i = 0; i < n; i++)
        cin >> positionX[i];
    
    vector<int> positionY(n);
    for(int i = 0; i < n; i++)
        cin >> positionY[i];
    

    sort(positionX.begin(), positionX.end());
    sort(positionY.begin(),positionY.end());

    int midPoint = n/2;
    double midPointX = positionX[midPoint], midPointY = positionY[midPoint]; 
    if(n % 2 == 0){
        midPointX = (positionX[midPoint] + positionX[midPoint-1])/2;
        midPointY = (positionY[midPoint] + positionY[midPoint-1])/2;
    }
    double ans = 0;
    for(int i = 0; i < n; i++)
        ans += abs(positionX[i] - midPointX) + abs(positionY[i] - midPointY);
    printf("%.1f\n", ans);
    
    return 0;
}