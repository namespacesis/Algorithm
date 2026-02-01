li = list(map(int, input().split()))
cnt = len([n for n in li if n > 0])
print(cnt)