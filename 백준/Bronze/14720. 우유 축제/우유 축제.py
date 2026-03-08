N = int(input())
li = list(map(int, input().split()))
k = cnt = 0
for i in range(li.index(0), N):
    if li[i] == k:
        k = (k+1)%3
        cnt += 1
print(cnt)