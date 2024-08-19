import sys
input = sys.stdin.readline

direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]

R, C = map(int, input().split())
arr = [list(input().strip()) for _ in range(R)]

visited = [[''] * C for _ in range(R)]
result = 0

stack = [(0, 0, arr[0][0])]

while stack:
    x, y, path = stack.pop()

    if len(path) > result:
        result = len(path)
        if result == 26:
            break

    for dx, dy in direction:
        nx, ny = x + dx, y + dy
        if 0 <= nx < R and 0 <= ny < C and arr[nx][ny] not in path:
            new_path = path + arr[nx][ny]
            if new_path not in visited[nx][ny]:
                visited[nx][ny] = new_path
                stack.append((nx, ny, new_path))

print(result)
