#include <iostream>
#include <vector>

using namespace std;

static int N = 9;
static int TOTAL = 45;
vector<vector<int>> sudoku(N,vector<int>(N,0));
vector<pair<int,int>> blank;

bool check(int x, int y, int num){
    // 행 & 열
    for (int i = 0; i < 9; i++) {
        if (sudoku[x][i] == num) return false;
        if (sudoku[i][y] == num) return false;
    }

    // 3*3 박스
    int dx = (x/3)*3;
    int dy = (y/3)*3;
    for(int i=dx; i<dx+3; i++){
        for(int j=dy; j<dy+3; j++){
            if (sudoku[i][j] == num) return false;
        }
    }
    return true;
}


bool dfs(int idx) {
    // 모든 빈칸 채우면 끝
    if (idx == blank.size()) {
        return true;
    }

    int x = blank[idx].first;
    int y = blank[idx].second;

    for (int num = 1; num <= 9; num++) {
        // 가능한 숫자면 
        if (check(x, y, num)) {
            sudoku[x][y] = num;
            // 다음 blank 채우러 감
            // 이전과정에서 true면 끝 !
            if (dfs(idx + 1)) return true;

            // 못채우면 0으로 하고 다른 숫자 체크
            sudoku[x][y] = 0; 
        }
    }
    return false; // 여기에 가능한 숫자 없음
}

int main() {

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j]==0) blank.push_back({i,j});
        }
    }
    dfs(0);

    // 정답 출력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}