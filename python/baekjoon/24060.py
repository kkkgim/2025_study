

def merge_sort(sort_list):
    
    if len(sort_list) < 2:
        return sort_list

    mid = (len(sort_list)+1) // 2
    front_arr = merge_sort(sort_list[:mid])
    last_arr = merge_sort(sort_list[mid:])
    
    f_idx = l_idx = 0
    merge_arr = []
 
    while True:
          # 병합시 리스트 크기가 다른 경우
        if f_idx >= len(front_arr) or l_idx >= len(last_arr):
            while f_idx < len(front_arr):
                merge_arr.append(front_arr[f_idx])
                ans.append(front_arr[f_idx])

                f_idx += 1 
                
            while l_idx < len(last_arr):
                merge_arr.append(last_arr[l_idx])
                ans.append(last_arr[l_idx])

                l_idx += 1 

            return merge_arr
        
        if front_arr[f_idx] <= last_arr[l_idx]:
            merge_arr.append(front_arr[f_idx])
            ans.append(front_arr[f_idx])
            
            f_idx += 1
        else:
            merge_arr.append(last_arr[l_idx])
            ans.append(last_arr[l_idx])
            
            l_idx += 1
            


# 입력 처리
n, k = map(int, input().split())
sort_list = list(map(int, input().split()))


ans = []

merge_arr = merge_sort(sort_list)

if k > len(ans):
    print(-1)
else:
    print(ans[k-1])


