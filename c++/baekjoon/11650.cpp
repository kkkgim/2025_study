#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n ;
    vector<pair<int,int>> arr;
    pair<int,int> temp;

    for(int i=0; i<n; i++){
        cin >> temp.first >> temp.second;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    
    // 정렬된 배열 출력
    for(int i=0; i<n; i++){
        cout << arr[i].first << ' ' << arr[i].second  << '\n';
    }

    return 0;
}