#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<long long> v;
    long long x;
    while(n--){
        cin >> x;

        if(x!=0) v.push_back(x);
        else v.pop_back();
    }
    long long sum = 0;
    for(int i=0; i<v.size(); i++){
        sum += v[i];
    }

    cout << sum ;
    return 0;
} 