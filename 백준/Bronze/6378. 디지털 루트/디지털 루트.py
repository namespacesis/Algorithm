while 1:
    N = input()
    
    if N == '0' :
        break
    
    while 1:
        N = sum(list(map(int, str(N))))
        
        if N // 10 == 0 :
            print(N)
            break