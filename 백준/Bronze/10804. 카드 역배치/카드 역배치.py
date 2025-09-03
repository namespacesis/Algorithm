card = [i for i in range(21)]

for _ in range(10):
    a, b = map(int, input().split())
    
    for i in range((b-a+1)//2):
        temp = card[b-i]
        card[b-i] = card[a+i]
        card[a+i] = temp
        
for i in card[1:]:
    print(i, end = ' ')