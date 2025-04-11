#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,num;
    cin >> n;
    // 자료구조 큐, 스택 타입 입력
    int type[n];
    for(int i=0; i<n; i++){
        cin >> type[i];
    }

    // 자료구조 초기화
    deque<int> dq;
    for(int i=0; i<n; i++){
        cin >> num;
        // 큐인 경우만 데이터 삽입
        if(!type[i]){
            dq.push_back(num);
        }
    }

    // 삽입할 수열의 길이
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        dq.push_front(num);
        cout << dq.back() << ' ';
        dq.pop_back();
    }
    return 0;
}
