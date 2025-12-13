c = int(input())

for n in range(1, 100001):
    if c == 1:
        print(n)
        break

    if c % 2 == 0:
        c //= 2
    else:
        c = 3*c + 1