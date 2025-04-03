#include <iostream>
#include <string>
using namespace std;


void merge(int arr[], int temp[], int left, int mid, int right) {
    int left_1 = left;
    int left_2 = mid+1;

    int idx = 0;

    // 작은수부터 임시배열에 삽입
    while(left_1 <= mid && left_2  <= right){
        if(arr[left_1] < arr[left_2]) temp[idx++] = arr[left_1++];
        else temp[idx++] = arr[left_2++];
    }

    // 왼쪽 배열에 남은 요소 추가
    while (left_1 <= mid) temp[idx++] = arr[left_1++];

    // 오른쪽 배열에 남은 요소 추가
    while (left_2 <= right)  temp[idx++] = arr[left_2++];

    // 정렬된 임시배열을 기존배열에 삽입
    for(int i=0; i<idx; i++){
        arr[left+i]=temp[i];
    }
}


void mergeSort(int arr[], int temp[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid+1, right);

        merge(arr, temp, left, mid, right);
    }
}

int main() {
    // C 스타일 입출력과의 동기화 해제 (속도 증가)
    ios::sync_with_stdio(false); 
    // cin과 cout을 분리하여 실행 속도 향상
    cin.tie(NULL); 

    int n;
    cin >> n ;

    int arr[n];
    int temp[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    mergeSort(arr, temp, 0, n - 1);

    // 정렬된 배열 출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}