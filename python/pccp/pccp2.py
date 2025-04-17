def solution(diffs, times, limit):
    min_level = 1
    max_level = max(diffs)
        
    while min_level < max_level :
        level = (min_level+max_level)//2
        total_time = 0 
        
        for i in range(len(diffs)):
            diff = diffs[i]
            time_cur = times[i]
            time_prev = 0
            
            if i > 0 :
                time_prev = times[i-1]
                
            if diff <= level :
                total_time += time_cur
            if diff > level :
                total_time +=  ((diff - level) * (time_cur + time_prev)) + time_cur
        
        
        # 제한시간초과 시 최저레벨 올리기    
        if limit < total_time :
            min_level = level + 1
        elif limit >= total_time :
            max_level = level

            
    return min_level

