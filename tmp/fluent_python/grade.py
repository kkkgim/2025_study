import bisect

## 이진 탐색을 활용한 등급 반환 함수
def grade(score, breakpoints=[60,70,80,90], grades='FDCBA'):
    # 점수의 인덱스 값 반환 
    i = bisect.bisect(breakpoints,score)
    return grades[i]

print( [grade(score) for score in [33, 99,77, 70, 89, 90,100]] )