#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; 
    cin >> n ;

    long long wine[n+1];
    for(int i=1; i<=n; i++) cin >> wine[i];
    
    long long dp[n+1];
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    dp[3] = max(dp[2], wine[2]+wine[3]);
    dp[3] = max(dp[3], wine[1]+wine[3]);

    for(int i=4; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i-2]+wine[i]);
        dp[i] = max(dp[i], dp[i-3]+wine[i-1]+wine[i]);
    }

    cout << dp[n];
}