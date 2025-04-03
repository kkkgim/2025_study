#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬기준
bool compare(pair<pair<int, int>, string> p1, pair<pair<int, int>, string> p2){
    if(p1.first.first == p2.first.first) return p1.first.second < p2.first.second;
    else return p1.first.first < p2.first.first;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n ;

    vector<pair<pair<int, int>, string>> arr;
    int age ;
    string name;
    for(int i=0; i<n; i++){
        cin >> age >> name;
        arr.push_back({{age, i}, name});
    }

    // 정렬 기준 전달
    sort(arr.begin(), arr.end(), compare);

    // 정렬된 배열 출력
    for(int i=0; i<arr.size(); i++){
        cout << arr[i].first.first << ' ' << arr[i].second << '\n';
    }

    return 0;
}