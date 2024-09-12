import math

Min, Max, A, B = map(int,input().split())

def gcd(a,b):
    if b == 0: return a
    else: return gcd(b,a%b)

def checklcm(a,b):
    Max = max(a,b); Min = min(a,b)
    P = Max // gcd(a,b)
    PowP = math.log(P,10); PowMin = math.log(Min,10)
    if math.floor(PowP) + math.floor(PowMin) > 19: return 0 
    else: return  P * Min

def countdiv(Min,Max,N):
    if Min % N == 0: return Max // N - Min // N + 1
    else: return Max // N - Min // N

def solve(Min,Max,A,B):
    DivByA = countdiv(Min,Max,A)
    DivByB = countdiv(Min,Max,B)
    if checklcm(A,B) > 0: DivByAB = countdiv(Min,Max,checklcm(A,B))
    elif checklcm(A,B) == 0 and Min == 0: DivByAB = 1
    else: DivByAB = 0
    return DivByA + DivByB - 2 * DivByAB

answer = solve(Min,Max,A,B)
print(answer)
