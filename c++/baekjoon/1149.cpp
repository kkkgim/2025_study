#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> home(n,vector<int>(3,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> home[i][j];
        }        
    }

    // 0:R, 1:G, 2:B
    int idx=0;
    int dp[n][3];
    for(int i=0; i<n; i++){
        if(i==0){
            dp[i][0] = home[i][0];
            dp[i][1] = home[i][1];
            dp[i][2] = home[i][2];
        } 
        else{
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + home[i][0];
            dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + home[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + home[i][2];
        }
    }

    cout << min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]) ;
    
    return 0;
}
