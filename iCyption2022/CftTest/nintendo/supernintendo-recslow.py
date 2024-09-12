MOD = 10**9+9

def s(n):
    if n == 0: return 0
    elif n == 1: return 0
    elif n == 2: return 1
    else: return ((s(n-1)+s(n-2))%MOD + (2**(n-2))%MOD)%MOD

n = int(input())
print(s(n))
        