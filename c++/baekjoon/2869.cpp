#include <iostream>
#include <string>


int main() {
    long long A, B, V;
    std::cin >> A >> B >>  V;

    // 무조건 오르고 떨어지는 날 
    // 총 길이에서 오를 수 있는 길이를 뺀 것의 몫 == 무조건 올라야하는 일자
    long long day = (V-A) / (A-B);
    
    // 총 길이에서 오를 수 있는 길이를 뺐으므로, 나머지가 존재하면 2일을 추가
    if(((V-A) % (A-B))>0) day += 2;
    else day++;


    std::cout << day << std::endl;
    return 0;
} 

