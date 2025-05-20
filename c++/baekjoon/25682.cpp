#include <iostream>
#include <cstring>  

using namespace std;

int psumW[2001][2001];
int psumB[2001][2001];

int main(){
    // C++ 입출력 최적화
    ios::sync_with_stdio(false);
    // cin 실행 후 cout 자동 flush 방지
    cin.tie(NULL);  

    int n,m,k;
    cin >> n >> m >> k;
    
    int diffW[n][m];
    int diffB[n][m];
    memset(diffW, 0, sizeof(diffW));
    memset(diffB, 0, sizeof(diffB));

    int max_val = INT16_MAX;
    int idx = 0;
    char chess[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> chess[i][j];
            if((i+j)%2==0){
                if(chess[i][j]=='W'){
                    diffW[i][j] = 0;
                    diffB[i][j] = 1;
                }
                else{
                    diffW[i][j] = 1;
                    diffB[i][j] = 0;
                }
               
            }
            else{
                if(chess[i][j]=='B'){
                    diffW[i][j] = 0;
                    diffB[i][j] = 1;
                }
                else{
                    diffW[i][j] = 1;
                    diffB[i][j] = 0;
                }
            }
        }
    }


    // 누적합 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 1. 해당 위치의 값을 기본값으로 설정
            psumW[i][j] = diffW[i][j];
            psumB[i][j] = diffB[i][j];
            if (i > 0) {
                // 2. 위쪽 누적값 더함
                psumW[i][j] += psumW[i - 1][j];
                psumB[i][j] += psumB[i - 1][j];
            }
            if (j > 0) {
                // 3. 왼쪽 누적값 더함
                psumW[i][j] += psumW[i][j - 1];
                psumB[i][j] += psumB[i][j - 1];
            }
            if (i > 0 && j > 0) {
                // 4.중복값 제거
                psumW[i][j] -= psumW[i - 1][j - 1];
                psumB[i][j] -= psumB[i - 1][j - 1];
            }
        }
    }

    // k x k 구간별 최소 변경 횟수 구하기
    int result = INT32_MAX;
    for (int i = k - 1; i < n; i++) {
        for (int j = k - 1; j < m; j++) {
            int totalW = psumW[i][j];
            int totalB = psumB[i][j];
            if (i - k >= 0) {
                // 1. 위쪽 누적값 제거
                totalW -= psumW[i - k][j];
                totalB -= psumB[i - k][j];
            }
            if (j - k >= 0) {
                // 2. 왼쪽 누적값 제거
                totalW -= psumW[i][j - k];
                totalB -= psumB[i][j - k];
            }
            if (i - k >= 0 && j - k >= 0) {
                // 3. 중복으로 제거된 부분 더함
                totalW += psumW[i - k][j - k];
                totalB += psumB[i - k][j - k];
            }
            result = min(result, min(totalW, totalB));
        }
    }

    cout << result << '\n';

    return 0;
}