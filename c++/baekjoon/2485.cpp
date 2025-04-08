#include <iostream>
#include <set>

using namespace std;

int get_gcd(int x , int y){
    while(y){
        int tmp = x%y;
        x=y;
        y=tmp;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    long ex,now;
    long diff[n-1];
    set<long> s;

    cin >> ex;
    for(int i=1; i<n; i++){
        cin >> now;
        diff[i-1]=now-ex;
        ex=now;
        s.insert(diff[i-1]);
    }

    // set의 반복자
    auto it = s.begin();
    long common_gcd = *it;
    ++it;
    
    while(it != s.end()) {
        common_gcd = get_gcd(common_gcd, *it);
        ++it;
    }
    long cnt = 0;
    n = n-1;
    while(n--){
        // 추가로 심어야 할 가로수의 수
        cnt += (diff[n]/common_gcd) - 1;
    }
    cout << cnt;
    
    return 0;
}