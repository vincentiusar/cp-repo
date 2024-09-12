import sys
sys.setrecursionlimit(1000000)

mapping = [[0 for i in range(1001)] for i in range(1001)]
isCheck = [[False for i in range(1001)] for i in range(1001)]

def IsInMap(n, i, j) :
    return (i >= 0 and j >= 0 and i < n and j < n)

def FindingRegion(i, j, n) :
    if(IsInMap(n,i,j)) :
        if (mapping[i][j] == 0) :
            return
        
        if(isCheck[i][j]) : return
        
        isCheck[i][j] = True
        if(mapping[i][j] == 1) :
            FindingRegion(i+1,j,n)
            FindingRegion(i-1,j,n)
            FindingRegion(i,j+1,n)
            FindingRegion(i,j-1,n)
            FindingRegion(i+1,j+1,n)
            FindingRegion(i+1,j-1,n)
            FindingRegion(i-1,j+1,n)
            FindingRegion(i-1,j-1,n)

def Solve(n) :
    count = 0
    for i in range(n) :
        for j in range(n) :
            if(isCheck[i][j] == False) :
                if(mapping[i][j] == 1) :
                    count += 1
                    FindingRegion(i,j,n)
    print(count)

n = int(input())
for i in range(n) :
    mapping[i] = list(map(int, input().split()))

Solve(n)