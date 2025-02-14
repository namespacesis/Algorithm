def gcd(a, b):
    if b > a:
        a, b = b, a
    if a % b == 0:
        return b
    return gcd(b, a % b)
 
def lcm(a, b):
    return a * b // gcd(a, b)
 
for _ in range(int(input())):
    a, b = map(int, input().split())
    print(lcm(a, b))