n = int(input())
seat = list(input())
cup = 1

cup = cup + seat.count("S") + (seat.count("L") // 2)
print(min(cup, n))