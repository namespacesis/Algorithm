import sys

def get_prime_list(limit):
    primes = [True] * (limit + 1)
    primes[0] = primes[1] = False
    for i in range(2, int(limit**0.5) + 1):
        if primes[i]:
            for j in range(i*i, limit + 1, i):
                primes[j] = False
    return primes

def solve():
    MAX_VAL = 246912
    prime_flags = get_prime_list(MAX_VAL)
    input_data = sys.stdin.read().split()
    
    for n_str in input_data:
        n = int(n_str)
        if n == 0:
            break
        print(sum(prime_flags[n+1 : 2*n + 1]))

if __name__ == "__main__":
    solve()