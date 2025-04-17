from collections import deque
import sys 

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n,m,start = map(int,input().split())


graph = { i : [] for i in range(0,n+1)}

for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

for key in graph:
    graph[key].sort()

visited = [0] * (n+1)
cnt = 1

def dfs(node):
    global cnt
    visited[node] = cnt
    cnt += 1

    for nd in graph[node]:
        if visited[nd] == 0:
            dfs(nd)

dfs(start)

print('\n'.join(list(map(str,visited[1::]))))





'''

5 5 1
1 4
1 2
2 3
2 4
3 4



'''
    