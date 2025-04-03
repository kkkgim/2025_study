#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m;
    std::cin >> n >> m;

    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());

    string str;
    int cnt = 0;
    for(int i=0; i<m; i++){
        cin >> str;
        int idx = lower_bound(arr.begin(), arr.end(), str) - arr.begin();
        if( idx < arr.size()  && str == arr[idx]) cnt++;
    }   

    cout << cnt ;

    return 0;
} 