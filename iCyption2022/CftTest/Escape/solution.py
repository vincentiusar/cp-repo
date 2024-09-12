n = int(input())

arr = [[0 for i in range(n)] for j in range(n)]

for i in range(n) :
    arr[i] = list(map(int, input().split()))
    for j in range(n-i): 
        arr[i].append(0)

reachable = [[False for i in range(n)] for j in range(n)]

reachable[0][0] = True;
for i in range(n-1):
    for j in range(n):
        if (reachable[i][j]):
            if (arr[i][j] >= arr[i+1][j]):
                reachable[i+1][j] = True
            if (arr[i][j] >= arr[i+1][j+1]):
                reachable[i+1][j+1] = True

bisa = False
for j in range(n):
    if (reachable[n-1][j]):
        bisa = True

if (bisa):
    print("BISA") 
else:
    print("MUSTAHIL")
