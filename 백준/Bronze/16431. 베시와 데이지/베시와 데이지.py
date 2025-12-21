bessie = list(map(int, input().split()))
daisy = list(map(int, input().split()))
john = list(map(int, input().split()))

bessie_turn = max(abs(john[0]-bessie[0]), abs(john[1]-bessie[1]))
daisy_turn = abs(john[0]-daisy[0])+abs(john[1]-daisy[1])

if bessie_turn < daisy_turn:
    print('bessie')
elif bessie_turn > daisy_turn:
    print('daisy')
else:
    print('tie')