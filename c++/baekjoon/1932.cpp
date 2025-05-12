#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;


    vector<int> dp(n, 0) ;
    
    for(int i=0; i<n; i++){
        vector<int> tmp(i+1,0);
        for(int j=0; j<i+1; j++){
            cin >> tmp[j];
        }
        if(i==0) dp[i] = tmp[i];
        else{
            for(int j=i; j>=0; j--){
            	// 1차원 배열을 사용하기에 앞에서부터 변경하면, 
                // dp[2] 비교할 때, 이미 바뀐 값으로 뒤에서 부터 계산
                if(j==i) dp[j] = dp[j-1] + tmp[j];
                else if(j==0) dp[j] += tmp[j];
                else{
                	// 중간에 있는 값들은 최대값만 저장하면 됨
                    dp[j] = max(dp[j-1], dp[j]) + tmp[j];
                }
            }
        }
    }

    int result = *max_element(dp.begin(), dp.end());
    
    cout << result;
    return 0;
}