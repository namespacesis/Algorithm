import sys

K = int(sys.stdin.readline())

for i in range(K):

    N, *array = map(int, sys.stdin.readline().split())

    array.sort()

    distance = 0
    
    for j in range(N-1):
        distance = max(distance, abs( array[j]-array[j+1]))
    
    print(f'Class {i+1}')
    print(f'Max {array[-1]}, Min {array[0]}, Largest gap {distance}')