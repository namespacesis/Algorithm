n = int(input())
data = list(map(int, input().split()))

result = 0
for i in range(1, n + 1) :
  if data[i-1] != i :
    result += 1

print(result)