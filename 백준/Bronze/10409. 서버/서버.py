import sys
input = sys.stdin.readline

n, T = map(int, input().split())
task = list(map(int, input().split()))

cnt = 0
for i in task:
    if i <= T:
        T -= i
        cnt += 1
    else:
        break
print(cnt)