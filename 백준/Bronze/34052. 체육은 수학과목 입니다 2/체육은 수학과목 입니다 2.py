res = 300

for _ in range(4):
    n = int(input())
    res += n

if res > 1800:
    print("No")
else:
    print("Yes")