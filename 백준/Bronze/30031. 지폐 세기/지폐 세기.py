n = int(input())
value = {136: 1000, 142: 5000, 148 : 10000, 154: 50000}
total = 0
for _ in range(n):
    w, h = map(int, input().split())
    total += value[w]
print(total)