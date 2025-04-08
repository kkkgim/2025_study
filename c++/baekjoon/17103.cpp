#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;
bool is_prime[MAX + 1];

// 2부터 시작해서 소수의 배수들을 지워나감
void sieve() {
    // true로 초기화
    fill(is_prime, is_prime + MAX + 1, true);
    // 0,1은 소수가 아니므로 false
    is_prime[0] = is_prime[1] = false;

    // 소수가 아닌 것 체크
    for(int i = 2; i <= sqrt(MAX); i++) {
        // 이미 지워진 수는 제외 
        // 해당 숫자의 배수는 이미 다 지워짐
        if(is_prime[i]) {
            // 소수의 배수를 제외
            // i*i부터 시작하는 이유
            // i보다 작은 수들에서 이미 지워졌기 때문에, i*i부터 시작해도 누락되는 소수가 없고, 중복 연산을 줄일 수 있음
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 소수 리스트 생성
    sieve();  

    int T,n;
    cin >> T;
    while(T--){
        cin >> n;

        // 파티션의 수 구하기
        int cnt = 0;
        for (int i = 2; i <= n / 2; i++) {
            // 소수의 합이 n이면 카운트
            if (is_prime[i] && is_prime[n - i]) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}