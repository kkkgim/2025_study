# 지시사항을 참고하여 코드를 작성하세요.
def check_str(text_str,open_str,close_str):
    while True:
        open_x = text_str.find(open_str)
        close_x = text_str.find(close_str)
        if open_x < close_x:
            text_str = text_str.lstrip(open_str)
            text_str = text_str.lstrip(close_str)
        else :
            return text_str

def check_1(text_str):
    text_str = text_str.replace('[','')
    text_str = text_str.replace(']','')
    text_str = text_str.replace('()','')
    
    return text_str

def check_2(text_str):
    text_str = text_str.replace('(','')
    text_str = text_str.replace(')','')
    
    while True:
        if text_str.find('[]') > -1:
            text_str = text_str.replace('[]','')
        else :
            return text_str


text_str = input()

# chk_1 = check_str(text_str,'(',')')
# chk_2 = check_str(chk_1,'[',']')

chk_1 = check_1(text_str)
chk_2 = check_2(text_str)

chk_2 = chk_2 + chk_1


if len(chk_2) == 0 :
    print('Yes')
else :
    print('No')

