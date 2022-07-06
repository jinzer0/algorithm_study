f0 = 0 # 0번째 피보나치 수
f1 = 1 # 1번째 피보나치 수

n = int(input()) 

for i in range(n-1): # n-1번 만큼 반복하여 f1에 f1값과 f0값의 합을, f0에 f1값을 할당
    f1, f0 = f1 + f0, f1

print(f1) # n번째 피보나치 수 출력