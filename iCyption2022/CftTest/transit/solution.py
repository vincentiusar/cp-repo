n, m = map(int, input().split())

g = [[] for i in range(n)]

for i in range(m):
    a, b = map(int, input().split())
    g[a - 1].append(b - 1)

src, target = map(int, input().split())
src -= 1
target -= 1

q = []
vis = [False for i in range(n)]

q.append([src, 0])
vis[src] = True

while len(q) > 0:
    cur, dist = q[0]
    q.pop(0)

    if cur == target:
        print(dist - 1)
        quit(0)

    for adj in g[cur]:
        if not vis[adj]:
            q.append([adj, dist + 1])
            vis[adj] = True
print(-1)
