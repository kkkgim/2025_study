#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,x;
    cin >> n ;
    
    vector<int> v;
    int now=1;
    for(int i=0; i<n; i++){
        cin >> x ;
        
        while (!v.empty() && v.back() == now) {
            v.pop_back();
            now++;
        }
        if(x == now) now++;
        else v.push_back(x);
    }

    while (!v.empty() && v.back() == now) {
        v.pop_back();
        now++;
    }

    if(v.empty()) cout << "Nice" ;
    else cout << "Sad";

    return 0;
} 