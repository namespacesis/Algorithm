n, m = map(int, input().split())
answer = [i for i in range(1, n+1)]

for _ in range(m):
    i, j, k= map(int, input().split())
    answer = answer[:i-1] + answer[k-1:j] + answer[i-1:k-1] + answer[j:]

print(' '.join(str(n) for n in answer))