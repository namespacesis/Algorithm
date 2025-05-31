n, m = map(int, input().split())

package = []
unit = []
for _ in range(m):
    x, y = map(int, input().split())
    package.append(x)
    unit.append(y)

p = min(package)
q = min(unit)

result = min(n//6 * p + n%6 * q, (n//6 + 1) * p, n * q)
print(result)