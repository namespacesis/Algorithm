import math

n, m = map(int, input().split(":"))
print(str(n//math.gcd(n, m))+":"+str(m//math.gcd(n, m)))