import math

EPS = 1e-4
N, X, Y, Z = map(float, input().split())

need = (N - 1) * 2 * math.sqrt(math.pow(X, 2) + math.pow(Y, 2)) + X

if (need - Z < EPS) :
    print("Bisa")
else :
    print("Tidak Bisa")