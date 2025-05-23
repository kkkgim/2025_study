#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T; 
    cin >> T;

    int dp[12];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    for(int i=4; i<12; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    while(T--){
        int num;
        cin >> num;
        
        cout << dp[num] << '\n';
    }
        

}