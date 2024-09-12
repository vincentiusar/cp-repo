import math as m

K, L = map(int, input().split())

def checkperfectsquare(n):
 r = m.sqrt(n)
 if int(r)**2 == n: return True
 else: return False

if K % 2 != 0: print("MUSTAHIL")
else:
 S = K // 2
 discriminant = S**2 - 4*L

 if discriminant < 0: print("MUSTAHIL")
 elif not(checkperfectsquare(discriminant)): print("MUSTAHIL")
 else:
  rdisc = int(m.sqrt(discriminant))
  if (S + rdisc)%2 != 0: print("MUSTAHIL")
  else: print("MUNGKIN")