def merge_sort(sort_list):

    if len(sort_list) < 2:
        return sort_list

    mid = len(sort_list) // 2
    front_arr = merge_sort(sort_list[:mid])
    last_arr = merge_sort(sort_list[mid:])
    
    f_idx = l_idx = 0
    merge_arr = []

    while f_idx < len(front_arr) and l_idx < len(last_arr):
        if front_arr[f_idx] <= last_arr[l_idx]:
            merge_arr.append(front_arr[f_idx])
            ans.append(front_arr[f_idx])
            
            f_idx += 1
        else:
            merge_arr.append(last_arr[l_idx])
            ans.append(last_arr[l_idx])
            
            l_idx += 1

    # 남은 요소 병합
    while f_idx < len(front_arr):
        merge_arr.append(front_arr[f_idx])
        ans.append(front_arr[f_idx])
        
        f_idx += 1

    while l_idx < len(last_arr):
        merge_arr.append(last_arr[l_idx])
        ans.append(last_arr[l_idx])
        
        l_idx += 1

    return merge_arr


# 입력 처리
n, k = map(int, input().split())
sort_list = list(map(int, input().split()))

ans = []  # 병합 과정에서 몇 번째 값인지 추적
result = -1  # K번째 값 저장 (기본값 -1)

merge_sort(sort_list)
print(ans)
if k > len(ans):
    print(-1)
else:
    print(ans[k-1])
    
    
''' 
    5 4 1 | 3 11 12 2 |  6 8 7  | 9 10 13 14
    
    5  | 4 1 | 3 11 12 2 |  6 8 7  | 9 10 13 14
    
    5  | 4 | 1 | 3 11 12 2 |  6 8 7  | 9 10 13 14
    
    5 | 1
    
'''