T = int(input())
 
for _ in range(T):
    A = input()
    B = input()
 
    count = 0
    for i in range(len(A)):
        if A[i] != B[i]:
            count += 1
    print("Hamming distance is {}.".format(count))
