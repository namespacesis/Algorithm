from collections import defaultdict

number_of_round = int(input())
for round_num in range(number_of_round):
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))

    A.pop(0)
    B.pop(0)

    A_dic, B_dic = defaultdict(int), defaultdict(int)
    for num in A:
        A_dic[num] += 1
    for num in B:
        B_dic[num] += 1

    for shape in range(4,0,-1):
        if A_dic[shape] > B_dic[shape] :
            print('A')
            break
        elif A_dic[shape] < B_dic[shape] :
            print('B')
            break
    else :
        print('D')