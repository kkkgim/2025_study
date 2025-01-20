import glob
import os

def read_files_and_mody(folder_path):
    texts = []
    # 폴더 내 모든 텍스트 파일 경로를 가져옵니다.
    file_paths = glob.glob(os.path.join(folder_path, '*.txt'))  

    for file_name in file_paths:
        with open(file_name, 'r', encoding='utf-8') as file:
            data = file.read()
            data = data.split('\n')
            print(data)

        

# 현재 경로의 특정 하위 폴더에서 텍스트 파일을 읽어옵니다.
folder_name = 'labels'  # 예시 폴더 이름
current_path = os.path.dirname(os.path.abspath(__file__))  # 현재 파일의 경로
folder_path = os.path.join(current_path, folder_name)

# 결과 출력
read_files_and_mody(folder_path)
