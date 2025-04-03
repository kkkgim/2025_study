#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m;
    std::cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());

    std::cin >> m;
    vector<int> chk_card(m);
    for(int i=0; i<m; i++){
        cin >> chk_card[i];
    }

    for(int i=0; i<m; i++){
        int idx = lower_bound(arr.begin(), arr.end(), chk_card[i]) - arr.begin();
        if( idx < arr.size()  && chk_card[i] == arr[idx]) cout << '1' << ' ';
        else cout << '0' << ' ' ;

    }
    return 0;
} 