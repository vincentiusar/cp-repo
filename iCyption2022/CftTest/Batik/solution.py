n = int(input())

grid = [[' ' for i in range(n)] for j in range(n)]
for i in range(n): grid[i][0] = '*'
for i in range(n): grid[0][i] = '*'
for i in range(n): grid[i][n-1] = '*'
for i in range(n): grid[n-1][i] = '*'
for i in range(n): grid[i][i] = '*'
for i in range(n): grid[i][n-i-1] = '*'

for i in range(n):
    for j in range(n):
        print(grid[i][j], end="")
    print()    
