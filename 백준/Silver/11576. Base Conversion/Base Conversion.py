A,B=map(int, input().split())
m=int(input())
arr=list(map(int,input().split()))
a=0
for i in range(m):
    a+=arr[m-i-1]*A**i


ans=''

while a:
    ans=' '+ans
    ans=str(a%B)+ans
    a//=B

print(ans)