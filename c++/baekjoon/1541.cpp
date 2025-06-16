#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

using namespace std;
vector<int> numbers;
vector<char> operators;
int idx = 0;


int main(){
    string text; 
    cin >> text; 
    
    int start_idx = 0, end_idx = 0;
    int plag = 0;
    int sum[2] = {0,0};

    for(auto ch : text){
        end_idx++;
        if('+'== ch){
            sum[plag] += atoi(text.substr(start_idx, end_idx - start_idx).c_str());
            start_idx = end_idx;
        }
        // - 기호가 나오면 그 뒤의 숫자는 모두 음수로 판단
        else if('-'== ch){
            sum[plag] += atoi(text.substr(start_idx, end_idx - start_idx).c_str());
            start_idx = end_idx;
            plag = 1;
        }
    }
    // 마지막 숫자
    sum[plag] += atoi(text.substr(start_idx).c_str());

    cout << sum[0] - sum[1];
}