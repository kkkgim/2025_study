#include <iostream>
#include <vector>

using namespace std;

int n;
int answer = 0;
// idx : x , value : y 로 취급
vector<int> queen; 

bool check(int row, int col){
    for(int i=0; i<row; i++){
        // 같은 열일때, 대각선 위 아래 방향 체크
        if(queen[i]==col || (i+queen[i]) == (row+col) || (i-queen[i]) == row-col ) return false;
    }
    return true;
}
void dfs(int row){
    if (row == n){
        answer++;
        return;
    }
    for (int col=0; col<n; col++){
        // 안겹치면 계속 확인
        if(check(row,col)){
            queen[row] = col;
            dfs(row + 1);
            queen[row] = -1;
        }
    }


}
int main() {
    cin >> n;
    queen.resize(n);
    dfs(0);
    cout << answer << "\n";
}