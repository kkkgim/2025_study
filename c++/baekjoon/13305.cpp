#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

using namespace std;

int main(){
    int N,tmp; 
    cin >> N; 
    
    vector<long> road_lens;
    for(int i=0; i<N-1; i++){
        cin >> tmp;
        road_lens.push_back(tmp);
    }

    vector<long> gas_pay;
    for(int i=0; i<N; i++){
        cin >> tmp;
        if(i==N-1) gas_pay.push_back(0);
        else gas_pay.push_back(tmp);
    }

    long sum = 0;
    long min_pay = gas_pay[0];
    long road_len = road_lens[0];

    for(int i=1; i<N; i++){
        if(min_pay < gas_pay[i]) road_len += road_lens[i];
        else {
            sum += min_pay*road_len;
            road_len = road_lens[i];
            min_pay = gas_pay[i];
        }
    }

    cout << sum ;
}