INF = 1000000005
g = []
timFound = []

def dfs(node, prev, timer) :
    timeFound[node] = min(timeFound[node], timer)
    for child in g[node]:
        if (child == prev) : continue
        dfs(child, node, timer + 1)

n, k = map(int, input().split())

g = [[] for i in range(n)]
timeFound = [INF for i in range(n)]

x, y = 0, 0
for i in range(n-1):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    g[x].append(y)
    g[y].append(x)

x = list(map(int, input().split()))
for i in x :
    i -= 1
    dfs(i, -1, 0)

maxo = max(timeFound)
ans = []

for i in range(n):
    if (timeFound[i] == maxo):
        ans.append(i + 1)

print(len(ans))
for x in ans:
    print(x, end=" ")
