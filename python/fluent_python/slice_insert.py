l = list(range(10))
print(l)

l[2:5] = [20,30]
print(l)

del l[5:7]
print(l)

l[3::2] = [11,22]
print(l)

# l[2:5] = 100
# 리스트에 데이터 삽입시 iter객체가 와야함

l[2:5]  =[100]
print(l)