#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
bool compare(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second){
        if(p1.first.length() == p2.first.length()) {
            return p1.first < p2.first;
        }
        else return p1.first.length() > p2.first.length();
    }
    return  p1.second > p2.second;
}

int main(){
    int T,m;
    cin >> T >> m ;
    
    string word;
    map<string,int> freq;

    while(T--){
        cin >> word;
        if(word.length() < m) continue;
        freq[word]++;
    }
    // map은 정렬 기준이 key 기준 고정
    // vector화 한 후 정렬
    vector<pair<string,int>> words(freq.begin(), freq.end());
    sort(words.begin(), words.end(), compare);

    for(auto &p : words) cout << p.first << '\n';
}