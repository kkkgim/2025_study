#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int min_ability = INT32_MAX;
int n;

vector<vector<int>> ability;
vector<int> team;


void dfs(int start, int depth){
    if(depth==n/2){
        int score_1 = 0;
        int score_2 = 0;

        // team 1 계산
        for(int i=0; i<depth; i++){
            for(int j=i+1; j<depth; j++) {
                score_1 += ability[team[i]][team[j]];
                score_1 += ability[team[j]][team[i]];
            }
        }

        // team2 계산
        // team1_list 있는 값을 set으로 옮겨서 빠르게 검사할 수 있도록 함
        unordered_set<int> exclude(team.begin(), team.end());
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            if (exclude.find(i) == exclude.end()) {
                tmp.push_back(i);
            }
        }

        for(int i=0; i<depth; i++){
            for(int j=i+1; j<depth; j++) {
                score_2 += ability[tmp[i]][tmp[j]];
                score_2 += ability[tmp[j]][tmp[i]];
            }
        }
        if( min_ability > abs(score_1-score_2) ) min_ability = abs(score_1-score_2) ;
    }

    for(int i=start; i<n; i++){
        team.push_back(i);
        dfs(i+1, depth+1);
        team.pop_back();
    }

}


int main(){
    cin >> n;
    ability.assign(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ability[i][j];
        }
    }

    dfs(0,0);
    cout << min_ability ;

    return 0;
}