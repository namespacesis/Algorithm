N=int(input())

for i in range(N):
    a,b= map(int, input().split())
    sum=0
    if a == 1:
        sum += 5000000
    elif a<4 and a>=2:
        sum+= 3000000
    elif a<7 and a>=4:
        sum+= 2000000
    elif a<11 and a>=7:
        sum+= 500000
    elif a<16 and a>=11:
        sum+= 300000
    elif a<22 and a>=16:
        sum+= 100000
    if b==1:
        sum+=5120000
    elif b<4 and b>=2:
        sum+= 2560000
    elif b<8 and b>=4:
        sum+= 1280000
    elif b<16 and b>=8:
        sum+= 640000
    elif b<32 and b>=16:
        sum+= 320000
    print(sum)