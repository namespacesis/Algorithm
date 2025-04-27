import sys  
input = sys.stdin.readline
N = int(input())  
array = [*map(lambda x:int(x) if x.isdigit() else x, input())]  
result = -int(1e9)  

def calc(num1, num2, s):  
    if s == '+':  
        return num1+num2  
    elif s == '-':  
        return num1-num2  
    else:  
        return num1 * num2  

def dfs(idx, prev):  
    global result  
    if idx >= N:  
        result = max(result, prev)  
        return
    if idx + 3 < N:  
        dfs(idx+4, calc(prev, calc(array[idx+1], array[idx+3], array[idx+2]), array[idx]))  
    dfs(idx+2, calc(prev, array[idx+1], array[idx]))  

if N == 1:  
    result = array[0]  
else:  
    dfs(1, array[0])  
print(result)