#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main(){
    int T,num;
    cin >> T;
    
    map<int,int> m_arr;
    vector<int> v_arr;
    long sum=0;
    for(int i=0; i<T; i++){
        cin >> num;
        v_arr.push_back(num);
        sum+=num;
        if(m_arr.find(num)==m_arr.end()) m_arr[num]=1;
        else m_arr[num]++;
    }
    sort(v_arr.begin(),v_arr.end());

    int max_freq = 0;
    vector<int> mode_candidates;

    // auto → 복사본 (성능 낭비 + 수정 안 됨)
    // auto& → 참조 (원본에 직접 접근)
    for(auto& p : m_arr){
        if(max_freq < p.second){
            max_freq = p.second;
            mode_candidates.clear();
            mode_candidates.push_back(p.first);
        } 
        else if(p.second==max_freq) mode_candidates.push_back(p.first);
    }

    int avg = round((double)sum / T);
    int median = v_arr[T/2];
    int mode = mode_candidates.size() == 1 ? mode_candidates[0] : mode_candidates[1];
    int range = v_arr.back() - v_arr.front(); 

    cout << avg << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range ;

}