#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> type(N);
    vector<int> data(N);

    for (int i = 0; i < N; i++) cin >> type[i];
    for (int i = 0; i < N; i++) cin >> data[i];

    deque<int> dq;

    // 큐인 자료구조만 저장
    for (int i = 0; i < N; i++) {
        if (type[i] == 0) dq.push_back(data[i]);
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
        cout << dq.front() << ' ';
        dq.pop_front();
    }

    return 0;
}
