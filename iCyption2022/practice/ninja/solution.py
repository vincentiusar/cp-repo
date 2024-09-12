N, A = map(int, input().split())
C = sorted(list(map(int, input().split())))
ans = 0
minReq = 0
for i in range(N):
    minReq = max(minReq + C[i], 2*C[i])
    if minReq <= A:
        ans += 1
    else:
        break
print(ans)