#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int n,k;
    cin >> n >> k;
    
    vector<pair<int, int>> items(n);
    for(int i = 0; i < n; i++){
        cin >> items[i].first >> items[i].second;
    }

    vector<int> dp(n + 1, 0);
    for(int i = 0; i < n; i++){
        int w = items[i].first;
        int v = items[i].second;
        
        // 최대 무게에서 거꾸로 돌면서 
        // dp[5] = max(dp[5], dp[2] + 6)
        // 무게 2에서 이 물건 추가했을 때의 가치와 비교해서 더 크면 갱신
        for (int j = k; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[k];
}

