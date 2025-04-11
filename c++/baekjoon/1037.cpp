#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    long min =0;
    long max = 0;
    long num;
    while(T--){
        cin >> num;
        if(!min) min = num;
        if(min>num) min = num;
        if(max<num) max = num;
    }
    cout << min*max << '\n';
}