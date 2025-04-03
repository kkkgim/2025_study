#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬기준
bool compare(string str1, string str2){
    if(str1.length() == str2.length()) return str1 < str2;
    else return str1.length() < str2.length();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n ;
    vector<string> arr;
    string str ;

    for(int i=0; i<n; i++){
        cin >> str;
        arr.push_back(str);
    }

    // 정렬 기준 전달
    sort(arr.begin(), arr.end(), compare);
    // unique(arr.begin(),arr.end() -> 
    arr.erase(unique(arr.begin(),arr.end()), arr.end());

    // 정렬된 배열 출력
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << '\n';
    }

    return 0;
}