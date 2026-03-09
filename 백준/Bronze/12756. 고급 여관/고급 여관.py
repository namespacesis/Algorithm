a1, r1 = map(int, input().split())
a2, r2 = map(int, input().split())
while (True):
    if (r1 <= 0) and (r2 <= 0):
        print("DRAW")
        break
    elif r1 <= 0:
        print("PLAYER B")
        break 
    elif r2 <= 0:
        print("PLAYER A")
        break
    r1 = r1 - a2
    r2 = r2 - a1