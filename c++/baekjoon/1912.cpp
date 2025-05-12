#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n+1];
    int dp[n+1]={-1000,};
    
    int total_max = -1000;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        if (i == 1) dp[i] = arr[i];
        else{
            // 이전값 + 현재값 < 현재 값이면 이전은 버려야함
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        }
        total_max = max(total_max, dp[i]);
    }

    cout << total_max <<'\n';
    return 0;
}
