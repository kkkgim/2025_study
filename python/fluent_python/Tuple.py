lax_coordinates = (33.9425, -118.408056)
city, year, pop, chg, area = ('Tokyo', 2003, 32450, 0.66, 8014)

traveler_ids = [('USA','31195855'),('BRA','CE342567'),('ESP','XDA205856')]

for passport in sorted(traveler_ids):
    print('%s/%s' % passport)

for country, _ in traveler_ids:
    print(country)


a,b, *rest = range(5)
print(a,b, rest)

a,b, *rest = range(2)
print(a,b,rest)

a, *body, c, d = range(5)
print(a, body, c, d)


*head, b, c, d = range(5)
print(head, b, c, d)