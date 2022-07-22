#넘파이 사용
import numpy as np
count = 0 #이동 경우의 수 (결과값)
input_data = input() #현재 나이트 위치
x = int(ord(input_data[0])) - 96 #a의 아스키 코드는 97
y = int(input_data[1])
data = np.array([x,y]) #나이트 위치에 대한 1*2 행렬
step = np.array([[-2,-1], [-1,-2], [1, -2], [2, -1], [2,1], [1,2], [-1,2],[-2,1]]) #이동 경우의 수에 대한 8*2 행렬
result = data + step #행렬의 덧셈 (data는 값이 복제되어 8*2 행렬이 됨)
for i in range (8):
    if result[i][0] > 0 and result[i][0] < 9 and result[i][1] > 0 and result[i][1] <9: #결과가 맵을 벗어나지 않는 경우
        count += 1
print(count)
#
