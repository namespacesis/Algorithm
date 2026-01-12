A, B, C, N = map(int, input().split())
def room():
    for a in range(101):
        for b in range(101):
            for c in range(101):
                if (a * A) + (b * B) + (c * C) == N:
                    return 1
    return 0

print(room())