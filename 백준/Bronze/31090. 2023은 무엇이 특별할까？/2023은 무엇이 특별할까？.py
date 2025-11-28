import sys

T = int(sys.stdin.readline())

for _ in range(T):
    N = sys.stdin.readline().rstrip()
    
    next_year = int(N) + 1
    divisor = int(N[-2:])

    if next_year % divisor == 0:
        print('Good')
    else:
        print('Bye')