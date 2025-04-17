from collections import deque
import sys 

input = sys.stdin.readline

n,m,start = map(int,input().split())

graph = { i : [] for i in range(0,n+1)}

for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

for key in graph:
    graph[key].sort(reverse=True)


visited = [0] * (n + 1)
cnt = 1
visited[start] = 1

dq = deque([start])

while dq:
    i = dq.popleft()

    for node in graph[i]:
        if visited[node]==0:
            dq.append(node)
            cnt += 1
            visited[node]=cnt

print('\n'.join(map(str,visited[1::])))

