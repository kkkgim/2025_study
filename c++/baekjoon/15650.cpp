#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

void dfs(int start, int depth) {
    if (depth == m) {
        for (int num : arr)
            cout << num << ' ';
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; ++i) {
        arr.push_back(i);
        // depth==m일때만 출력하니,
        // 되돌아와서 다음 분기가 있어도 m>depth로 출력 안됨
        dfs(i+1, depth + 1);
        arr.pop_back();
    }
}

int main() {
    cin >> n >> m;
    dfs(1,0);
    return 0;
}