M, P = map(int,input().split())
def gcd(A,B):
 if B == 0: return A
 else: return gcd(B,A%B)

def lcm(A,B):
 D = gcd(A,B)
 return A*B // D

print (lcm(M,P))