n = int(input())
check = '369'
cnt = 0
for num in range(1, n+1):
    for i in check:
        cnt += str(num).count(i)
print(cnt)