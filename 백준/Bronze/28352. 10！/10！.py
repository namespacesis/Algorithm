def factorial(n):
    if n < 2:
        return 1
    else:
        return n * factorial(n - 1)
    
N = int(input())

num = factorial(N)
result = num //(7*24*60*60)

print(result)