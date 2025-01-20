from array import array
from random import random

floats = array('d', (random() for i in range(10**7)))
print(floats[-1])


fp = open ('floats.text','wb')
floats.tofile(fp)
fp.close()

floats2 = array('d')
fp = open('floats.text', 'rb')
floats2.fromfile(fp, 10**7)
fp.close
print(floats2[-2])

print(floats2==floats)