
def cantor(arr):
    idx = len(arr)//3
    
    if len(arr) == 1 :
        return arr
        
    return cantor(arr[0:idx])+ ' ' * idx +cantor(arr[idx*2:])


while True:
    try:
        n = int(input())
        arr = '-'*3 ** n

        print(cantor(arr))
    except EOFError:
        break
