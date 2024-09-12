A, B, N = map(int, input().split())

def solve(A,B,N):
    Max = max(A,B); Min = min(A,B)
    NumMax = N // Max
    while (N - Max * NumMax) % Min != 0 and NumMax > 0:
        NumMax -= 1
    NumMin = (N - Max * NumMax) // Min
    if Max * NumMax + Min * NumMin == N:
        if Max == A and Min == B: return (NumMax,NumMin)
        else: return (NumMin,NumMax)
    else: return "Mustahil"

R = solve(A,B,N)

if R == "Mustahil": print("Pesan Ulang")
else: print(R[0],R[1],sep=' ')