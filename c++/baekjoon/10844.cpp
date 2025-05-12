#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int n ;
    cin >> n;

    long div = 1000000000;
    long long dp[101][11];

	dp[1][10] = 9;
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
    
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[2][2] = 2;
	dp[2][3] = 2;
	dp[2][4] = 2;
	dp[2][5] = 2;
	dp[2][6] = 2;
	dp[2][7] = 2;
	dp[2][8] = 2;
	dp[2][9] = 1;
    dp[2][10] = 17;

    for(int i=3; i<=n; i++){
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];

        dp[i][10] = dp[i][0] + dp[i][9];
		for (int j = 1; j < 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % div;
			dp[i][10] = (dp[i][10]+dp[i][j]) % div;
		}
    }
    cout << dp[n][10];
}

