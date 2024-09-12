def sum(a,b):
    if (((a % 2 != 0) and (b % 2 == 0)) or ((a % 2 == 0) and (b % 2 != 0))):
        c = (a+b)
        d = (b-a+1)//2
        return c*d
    else: 
       c = (a+b)//2
       d = (b-a+1)
       return c*d

def summatrix(i1,j1,i2,j2):
    return (j2 - j1 + 1)*sum(i1,i2) + (i2 - i1 + 1)*sum(j1,j2)
    
def summatslow(i1,j1,i2,j2):
    thesum = 0
    for i in range(i1,i2+1):
        for j in range(j1,j2+1):
            thesum += i+j
    return thesum
    
m, n = map(int, input().split())
i1,j1, i2, j2 = map(int, input().split())
print(summatrix(i1,j1,i2,j2))