invoice = '''
001 taerin kim 
002 hoging lee
003 qdqwd  lee
'''

id = slice(0,3)
name = slice(4,10)
last_name = slice(11,None)


items = invoice.split('\n')[1:]

for item in items:
    print(item[id])
    print(item[name], item[last_name])
    