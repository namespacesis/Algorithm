import sys
import math

input = sys.stdin.readline

def solve():
    rh_req, rv_req, sh_req, sv_req = map(int, input().split())
    
    n = int(input())
    
    res = float('inf')
    
    for _ in range(n):
        rh, rv, sh, sv, price = map(int, input().split())
        
        nx1 = max(math.ceil(rh_req / rh), math.ceil(sh_req / sh))
        ny1 = max(math.ceil(rv_req / rv), math.ceil(sv_req / sv))
        cost1 = nx1 * ny1 * price
        
        nx2 = max(math.ceil(rh_req / rv), math.ceil(sh_req / sv))
        ny2 = max(math.ceil(rv_req / rh), math.ceil(sv_req / sh))
        cost2 = nx2 * ny2 * price
        
        temp = min(cost1, cost2)
        
        if temp < res:
            res = temp
            
    print(int(res))

solve()