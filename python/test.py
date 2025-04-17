import matplotlib.pyplot as plt

# 데이터 생성
AB = [(0, 0), (10, 0)]  # 변 AB의 두 점
AC = [(0, 0), (0, 10)]  # 변 AC의 두 점
D = AB[0]
E = AB[1]
F = AC[0]
G = (6, 6)  # 변 AC 위에 있는 점 G

# 삼각형 ABC와 사각형 DEGF 그리기
plt.figure(figsize=(10, 6))

# 삼각형 ABC
plt.plot(*zip(*AB), color='black')
plt.plot(*zip(*AC), color='black')
plt.fill_between([AB[0][0], F[0], G[0], AC[1][0]], [AB[0][1], F[1], G[1], AC[1][1]], color='lightgrey')

# 사각형 DEGF
plt.plot(*[(D[0], D[1]), (E[0], E[1]), (G[0], G[1]), (F[0], F[1])], color='black')
plt.fill_between([D[0], E[0], G[0], F[0], D[0]], [D[1], E[1], G[1], F[1], D[1]], color='yellow')

# 텍스트 추가
plt.text(D[0], D[1]-0.5, 'D', fontsize=12, ha='center')
plt.text(E[0], E[1]-0.5, 'E', fontsize=12, ha='center')
plt.text(F[0], F[1]-0.5, 'F', fontsize=12, ha='center')
plt.text(G[0], G[1]-0.5, 'G', fontsize=12, ha='center')

# 축 제거 및 그래프 표시
plt.axis('off')
plt.show()