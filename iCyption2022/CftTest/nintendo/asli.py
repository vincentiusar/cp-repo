MOD = 10**9 + 9

def identity(n):
    return [[1 if i == j else 0 for j in range(n)] for i in range(n)]

def multiply(a, b):
    rowA, colA = len(a), len(a[0])
    rowB, colB = len(b), len(b[0])
    assert(colA == rowB)
    R = [[0 for i in range(colB)] for j in range(rowA)]
    for i in range(rowA):
        for j in range(colB):
            R[i][j] = 0
            for k in range(colA):
                R[i][j] = (R[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD
    return R

def modmatexpo(A, k):
    row, col = len(A), len(A[0])
    assert(row == col)
    Res = identity(row)
    while k > 0:
        if k % 2 == 1: Res = multiply(Res, A)
        k //= 2
        A = multiply(A, A)
    return Res

n = int(input())
s0, s1, s2 = 0, 0, 1
A = [[1,1,0,2],[1,0,0,0],[0,1,0,0],[0,0,0,2]]
Res = [[0 for i in range(4)] for j in range(4)]
s = [[s2],[s1],[s0],[1]]
if n == 2:
    print(1)
else:
    Res = modmatexpo(A, n - 2)
    Product = multiply(Res, s)
    print(Product[0][0])
