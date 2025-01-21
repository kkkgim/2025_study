from collections.abc import Mapping

def process_data(data):
    if isinstance(data, Mapping):
        # 매핑 형식의 동작을 수행하는 코드
        keys = list(data.keys())
        values = list(data.values())
        print("Keys:", keys)
        print("Values:", values)
    else:
        print("Unsupported data type")

# 매핑 형식의 객체를 전달하여 처리
process_data({"a": 1, "b": 2, "c": 3})

# 매핑 형식이 아닌 객체를 전달하여 처리
process_data([1, 2, 3])
