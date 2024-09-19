total=0
answer=0
for i in range(10):
    N,M=map(int,input().split())
    total=total-N+M
    if(answer<total):
        answer=total
print(answer)