T = int(input())

for _ in range(T):
    N = list(map(int, input().split()))
    N.sort()
    print(N[-3])