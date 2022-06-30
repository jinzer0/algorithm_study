f0 = 0
f1 = 1

n = int(input())

for i in range(n-1):
    f1, f0 = f1 + f0, f1

print(f1)