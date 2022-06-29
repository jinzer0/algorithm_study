n = int(input())
int_list = []

for i in range(n):
    int_list.append(int(input()))

int_list.sort()

for i in int_list:
    print(i)