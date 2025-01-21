import dis

print(dis.dis('s[a] += b'))
t = (1,2,[30,40])
try: 
    
    t[2] += [50, 60]
    # t[2].extend([50,60])
    print(t)
except Exception as e :
    print(e)
    print(t)