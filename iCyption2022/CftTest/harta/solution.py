n = int(input())
a, b, x = map(int, input().split())

arr = [0 for i in range(100001)]
tree = [[] for i in range(n+1)]

def dfs(node, prev, time) :
    arr[node] = time
    for adj in tree[node]:
        if (adj != prev) :
            dfs(adj, node, time+1)

for i in range(1, n) :
    A, B = map(int, input().split())
    tree[A].append(B)
    tree[B].append(A)

dfs(x, -1, 0)
ruteA = arr[a]
ruteB = arr[b]

dfs(a, -1, 0)
ruteA += arr[b]
ruteB += arr[b]

print(min(ruteA, ruteB))