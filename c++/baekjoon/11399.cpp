#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){
    // N(1 ≤ N ≤ 1,000)
    int N;
    cin >> N;

    int time;
    vector<int> arr;
    while(N--){
        cin >> time;
        arr.push_back(time);
    }
    // 인출 시간이 짧아야, 기다리는 시간이 짧아짐
    sort(arr.begin(), arr.end());

    int total_time = 0;
    int waiting_time = 0;
    for(auto times :arr){
        // 기다린 시간 + 인출하는 시간
        waiting_time += times;
        // 모든 사람들의 시간 합
        total_time += waiting_time;
    }
    cout << total_time ;
}