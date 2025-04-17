import sys
from collections import deque


input = sys.stdin.readline
n, m, start = map(int,input().split())

graph = {i:[] for i in range(n+1)}

for _ in range(m):
    a, b = map(int,input().split())

    graph[a].append(b)
    graph[b].append(a)

for key in graph:
    graph[key].sort()

# print(graph)


# 0번은 사용 안함
visited = [0] * (n+1)

def dfs(node):
    global cnt
    print(node, end=' ')
    visited[node]= True

    for nd in graph[node]:
        if not visited[nd]:
            dfs(nd)

dfs(start)

print('')

def bfs():
    visited = [0] * (n+1)

    dq = deque([start])
    visited[start] = True

    while dq:
        nd = dq.popleft()
        print(nd, end=' ')
        for nd in graph[nd]:
            if not visited[nd]:
                dq.append(nd)
                visited[nd]=True

bfs()


'''

4 5 1
1 2
1 3
1 4
2 4
3 4

'''