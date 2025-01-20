from collections import Counter

def move(points):
    start_p, destination_p = points
    start_x, start_y = start_p
    destination_x,destination_y = destination_p
    
    # x좌표 먼저 이동
    if start_x != destination_x :
        start_x += 1 if start_x < destination_x else -1
    elif start_y != destination_y :
        start_y += 1 if start_y < destination_y else -1
            
    return [start_x,start_y]

def crash_check(mac_route):
    
    first_elements = [tuple(value[0]) for value in mac_route.values()]
    counter = Counter(first_elements)

    # 중복된 튜플만 출력
    duplicates = {item: count for item, count in counter.items() if count > 1}

    return len(duplicates)

def solution(points, routes):
    ## 초기화
    point_dict = {index+1: value for index, value in enumerate(points)} 
    mac_dict = {index+1: value for index, value in enumerate(routes)} 
    
    for key in mac_dict:
        for i,v in enumerate(mac_dict[key]):
            mac_dict[key][i] = point_dict[v]

    ## 충돌 계산
    # 초기 충돌
    crash_cnt = crash_check(mac_dict)

    while len(mac_dict)>0:
        # 이동    
        for key in mac_dict:
            points = mac_dict[key][0:2]           
            mac_dict[key][0] = move(points)
            
        # 충돌 검사
        crash_cnt += crash_check(mac_dict)
        
        #--- 딕셔너리의 원본을 직접 수정하면 안되기에, 키값을 리스트로 반환 후 딕셔너리에 접근 ---#
        for key in list(mac_dict):
            # 도착지점에 도착하면 시작점 제거
            if mac_dict[key][0] == mac_dict[key][1] :
                mac_dict[key].pop(0)
            # 마지막까지 도착하면 해당 mac 제거
            if len(mac_dict[key]) == 1:
                del mac_dict[key]
                
    return crash_cnt

print(f'crash_cnt : {solution([[3, 2], [6, 4], [4, 7], [1, 4]], [[4, 2], [1, 3], [4, 2], [4, 3]])}')
print(f'crash_cnt : {solution([[2, 2], [2, 3], [2, 7], [6, 6], [5, 2]],	[[2, 3, 4, 5], [1, 3, 4, 5]])}')

