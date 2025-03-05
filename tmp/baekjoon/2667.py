import sys
from collections import deque


n = int(input())

MAP = []
for _ in range(n):
    MAP.append(list(input()))


dx = [-1,1,0,0]
dy = [0,0,-1,1]

cnt = 0 
block_cnt = []


def DFS(x,y):
    global cnt

    if x < 0 or x >= n  or y < 0 or y >= n:
        return 0
    
    # 1을 찾으면 dfs 실행
    if int(MAP[x][y]) == 1:
        cnt += 1
        MAP[x][y] = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            DFS(nx,ny)
    

for i in range(n):
    for j in range(n):
        DFS(i,j)
        if cnt > 0:
            block_cnt.append(cnt)
            cnt = 0
    
    
block_cnt.sort()
print(len(block_cnt))
print('\n'.join(list(map(str,block_cnt))))
    

            

    
    



'''

7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

'''