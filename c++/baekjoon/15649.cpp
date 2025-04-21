// #include <iostream>
// #include <list>
// #include <vector>
// using namespace std;


// void pop(list<int> num_list, int num, string result , int n) {
//     if (n == 1) {
//         cout << result + to_string(num) + "\n";
//     } else {
//         string current = to_string(num) + " ";
//         num_list.remove(num);
//         for(auto st : num_list) {
//             pop(num_list, st , result+current, n-1) ;  // 결과 누적
//         }
//     }
// }

// int main(){
//     int x, y;
//     cin >> x >> y;

//     list<int> num_list;
//     for(int i=1; i<=x; i++){
//         num_list.push_back(i);
//     }
//     for(int i=1; i<=x; i++){
//         pop(num_list, i, "", y) ;
//     }
// }



#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
// 전역변수는 초기화 하지 않아도 false로 자동 초기화
bool visited[10];

void dfs(int depth) {
    if (depth == m) {
        for (int num : arr)
            cout << num << ' ';
        cout << '\n';
        return;
    }


    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            arr.push_back(i);
            dfs(depth + 1);
            arr.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(0);
    return 0;
}