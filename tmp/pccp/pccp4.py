import re
from collections import defaultdict

def get_base(expressions):
    one_digit_numbers = []
    
    for ex in expressions:
        numbers = re.findall(r'\d', ex)
        one_digit_numbers.extend([int(num) for num in numbers if len(num) == 1])
        
    min_base = max(one_digit_numbers) 
    
    return [i for i in range(min_base+1,10)]

def change_base(number, base):
    result_number = ''
    while number > 0:
        remainder = number % base  # 나머지 계산
        result_number = str(remainder) + result_number  # 나머지를 앞에 붙여서 저장
        number = number // base  # 몫을 다시 할당
        
    if result_number=='':
        result_number = '0'
        
    return result_number

def compute(ex, base):
    operand1, operator, operand2 , _, result = ex.split(' ')

    # 10진법으로 계산
    decimal_number_1 = int(str(operand1), base)
    decimal_number_2 = int(str(operand2), base)
    
    operators = {
        '+': lambda a, b: a + b,
        '-': lambda a, b: a - b
    }
    origin_result = operators[operator](int(decimal_number_1), int(decimal_number_2))
    
    if result != 'X':
        if origin_result == int(str(result), base):
            return True
        else:
            return False
    else :
        return f'{operand1} {operator} {operand2} {_} {change_base(origin_result, base)}'


def get_result_base(expressions, base_list):
    for ex in expressions:
        for base in base_list[:]:
            if not compute(ex, base):
                # 가능한 진법만 남김
                base_list.remove(base)
    
    return base_list 

def get_answer(expressions, result_base):
    answer_dict = defaultdict(set)
    for base in result_base:
        for ex in expressions :
            result = compute(ex, base)
            if result != None :   
                answer_dict[ex].add(compute(ex, base))
    
    answer = []
    for key, value in answer_dict.items():
        if len(value)==1:
            answer.append(list(value)[0])
        else :
            answer.append(key.replace('X','?'))
            
    return answer      

def solution(expressions):
    base_list = get_base(expressions)

    ex1 = [ex for ex in expressions if 'X' not in ex ]
    ex2 = [ex for ex in expressions if 'X' in ex ]
    
    result_base = get_result_base(ex1, base_list)
    answer = get_answer(ex2, result_base)

    return answer

