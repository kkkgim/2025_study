from collections import namedtuple

City = namedtuple('City', 'name country population coordinates')
tokyo = City('Tokyo', 'JP', 36.933, (35.689722,139.691667))

# fields 는 클래스의 필드명을 담고 있는 튜플
print(City._fields)

LatLong =  namedtuple('LatLong','lat long')

delhi_date = ('Delhi NCR', 'IN', 21.935, LatLong(28.613889, 77.208889))
# make()는 반복형 객체로부터 명명된 튜플을 만든다.
delhi = City._make(delhi_date)

# asdict은 명명된 튜플 객체에서 만들어진 collections.OrderedDict 객체를 반환 
print(delhi._asdict())



