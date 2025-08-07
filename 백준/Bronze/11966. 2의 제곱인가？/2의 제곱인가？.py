import sys

n = int(sys.stdin.readline())

if (n & (n - 1) == 0):
    print(1)
else:
    print(0)