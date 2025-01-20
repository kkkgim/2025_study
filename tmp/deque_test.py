from collections import deque

dq = deque(range(10), maxlen=10)
print(dq)

# 양수 인수를 받으면 오른쪽 끝에서 n개를 왼쪽 끝으로
# 음수 인수를 받으면 왼쪽 끝에서 n개를 오른쪽 끝으로
dq.rotate(3)
print(dq)

dq.rotate(-4)
print(dq)

# 가득 찬 덱(len(d) == d.maxlen)에 항목을 추가하면 반대쪽 항목을 삭제
dq.appendleft(-1)
print(dq)

# extend(iter) 오른쪽에 항목을 추가하면 왼쪽 항목이 삭제
dq.extend([11,22,33])
print(dq)


# extendleft(iter)는 덱의 왼쪽에 하나씩 차례대로 추가
dq.extendleft([10,20,30,40])
print(dq)
