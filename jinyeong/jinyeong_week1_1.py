n = int(input()) # n 입력 받기
int_list = [] # 입력 받은 정수를 저장할 리스트 생성

for i in range(n): # 정수를 n번 입력 받아 int_list에 삽입
    int_list.append(int(input())) 

int_list.sort() # int_list 오름차순 정렬

for i in int_list: # int_list내 요소를 하나씩 출력
    print(i)