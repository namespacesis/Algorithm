N, W, H, L = map(int, input().split())

cow = (W//L) * (H//L)

print(min(N, cow))