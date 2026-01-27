t = int(input())
for _ in range(t):
    a, b = input().split()
    if a == b:
        print('OK')
    else:
        print('ERROR')