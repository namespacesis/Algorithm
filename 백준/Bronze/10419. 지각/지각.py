from sys import stdin

for _ in range(int(stdin.readline())):
    d = int(stdin.readline())
    ans = 0
    for i in range(100, 0, -1):
        if i + i ** 2 <= d:
            ans = i
            break
    print(ans)