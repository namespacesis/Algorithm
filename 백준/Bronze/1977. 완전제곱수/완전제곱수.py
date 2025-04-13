def is_square(n): 
    return int(n ** 0.5) ** 2 == n

s = 0
for i in range(int(input()), int(input())+1):
    if is_square(i):
        if s == 0:
            minimum = i
        s += i

if s == 0:
    print(-1)
else:
    print(s)
    print(minimum)