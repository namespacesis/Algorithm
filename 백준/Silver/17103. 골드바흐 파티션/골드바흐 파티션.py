def find_prime(n):
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, n + 1, i):
                sieve[j] = False
    return sieve

def count_prime(n, arr):
    count = 0
    for k in range(2, (n // 2) + 1):
        if arr[k] and arr[n - k]:
            count += 1
    return count

T = int(input())

max_num = 1000000
prime_num = find_prime(max_num)

for _ in range(T):
    n = int(input())
    print(count_prime(n, prime_num))
