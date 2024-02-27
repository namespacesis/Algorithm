def solve(row, ld, rd):
    if row == ALL_ONES:
        return 1

    count = 0
    pos = ALL_ONES & ~(row | ld | rd)
    while pos:
        p = pos & -pos  # 가장 오른쪽 1비트를 가져옴
        pos -= p  # p 위치의 비트를 끔
        count += solve(row+p, (ld+p) << 1, (rd+p) >> 1)
    return count


N = int(input())
ALL_ONES = (1 << N) - 1  # N개의 모든 비트가 1인 수

print(solve(0, 0, 0))
