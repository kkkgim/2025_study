#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main(){
    string a,b;

    getline(cin, a);
    getline(cin, b);

    int n = a.length(), m = b.length();
    vector<vector<int>>  dp(n, vector<int>(m, 0));

    //// 같은 문자열이 없으면 이전 값 계승함
    // 첫 행 초기화
    for(int i=0; i<n; i++)
        if(a[i] == b[0]) dp[i][0] = 1;
        else if(i > 0) dp[i][0] = dp[i-1][0];

    // 첫 열 초기화
    for(int j=0; j<m; j++)
        if(b[j] == a[0]) dp[0][j] = 1;
        else if(j > 0) dp[0][j] = dp[0][j-1];


    for(int i=1; i<a.length(); i++){  
        for(int j=1; j<b.length(); j++){
            if (a[i] == b[j]) // 이전부분에서 + 1
                dp[i][j] = dp[i-1][j-1] + 1;
            else // 이전의 최장 공통 부분 갖고옴
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n-1][m-1];
}

