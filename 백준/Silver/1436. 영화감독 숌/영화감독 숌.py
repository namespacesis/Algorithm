N = int(input())

cnt = 0

for i in range(1, 99999999):
    if '666' in str(i):
        cnt+=1
    if cnt == N:
        print(i)
        break