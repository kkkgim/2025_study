#include <iostream>
#include <string>

using namespace std;

int cnt = 0;
int k ;

void merge(int arr[],int left, int mid, int right) {
    int i = left;
    int j = mid+1;
    int idx = left;

    int tmp[right+1]; 
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) tmp[idx++] = arr[i++];            
        else tmp[idx++] = arr[j++];   
    }

    while (i <= mid) tmp[idx++] = arr[i++];
    while (j <= right) tmp[idx++] = arr[j++];

    idx = left;
    while(idx<=right){
        cnt++;
        if(cnt==k) {
            cout << tmp[idx];
        }
        arr[idx] = tmp[idx];
        idx++;
    } 
    
}

void merge_sort(int arr[], int left, int right) { 
    if(left < right) {
        int mid = (left+right) / 2;     
        merge_sort(arr, left, mid);      
        merge_sort(arr, mid+1, right);  
        merge(arr, left, mid, right);        
    }
}

int main(){
    int n,x;
    cin >> n >> k;
    
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];        
    }   
    merge_sort(arr, 0,n-1);
    if(cnt < k) cout << "-1" ;

    return 0;
}