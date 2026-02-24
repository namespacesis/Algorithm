N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
 
result = 0
 
for i in range(N):
    result += abs(a[i] - b[i])
 
print(result // 2)