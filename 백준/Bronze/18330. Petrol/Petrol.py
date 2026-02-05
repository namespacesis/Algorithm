n = int(input())
k = int(input())

cost = 0
cheap = k+60

if n <= cheap:
    print(n*1500)
else:
    print(cheap*1500 + (n-cheap)*3000)