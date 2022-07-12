"""
hyeri_week2_2.py
c언어로 작성하고 싶었지만 실패해서 파이썬으로 작성하니다
완성하면 c언어로도 추후에 올리겠습니다
"""

#n행,m열 입력받고 공백으로 구분하기
n,m = map(int,input().split())

result =0

for i in range(n):
    data = list(map(int,input().split()))

    #가장 작은 수 찾기
    min_value = min(data)

    #가장 작은 수 중에서 가장 큰 수 찾기
    result = max(result, min_value)

print(result)

