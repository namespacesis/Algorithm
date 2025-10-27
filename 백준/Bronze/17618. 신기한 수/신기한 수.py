result = 0

for A in range(1, int(input())+1):
    B = 0
    temp = A
    while temp:
        B += temp % 10
        temp //= 10
    if A % B == 0:
        result += 1
        
print(result)