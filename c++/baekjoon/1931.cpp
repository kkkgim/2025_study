#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


int main(){
    // N(1 ≤ N ≤ 100,000)
    int N;
    cin >> N;

    int start,end;
    vector<pair<int, int>> arr;
    while(N--){
        cin >> start >> end;
        arr.push_back({end, start});
    }
    // 끝나는 시간 기준으로 오름차순으로 정렬하여
    // 빨리 끝나는 회의들을 먼저 카운트 할 수 있게 함
    sort(arr.begin(), arr.end());

    int cnt = 0;
    int end_time = 0;

    for(auto times :arr){
        // 끝나는 시간과 시작 시간을 비교하여 회의 개수 카운트
        if(times.second >= end_time){
            cnt++;
            end_time = times.first;
        }
    }
    cout << cnt ;

}