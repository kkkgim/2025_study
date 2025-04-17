import sys
from collections import deque, defaultdict

input = sys.stdin.readline  # 빠른 입력 사용
n, m, start = map(int, input().split())

# defaultdict를 사용하여 그래프 구성
graph = defaultdict(list)

# 무방향 그래프 입력 받기
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# 인접 리스트 정렬 (작은 노드부터 방문)
for key in graph:
    graph[key].sort()

# BFS 수행
dq = deque([start])
visited = [0] * (n + 1)  # 방문 순서 저장 배열
cnt = 1  # 방문 순서

visited[start] = cnt  # 시작 노드를 1번째 방문

while dq:
    i = dq.popleft()
    
    for node in graph[i]:  # 현재 노드와 연결된 노드 탐색
        if visited[node] == 0:  # 방문하지 않은 경우
            cnt += 1
            visited[node] = cnt  # 방문 순서 저장
            dq.append(node)

# 결과 출력 (모든 노드 방문 순서 출력)
print("\n".join(map(str, visited[1:])))  # 줄바꿈 한 번에 출력
