from collections import deque

nextDis = [[] for i in range(101000)]
BFS = deque()
getCost = deque()
level = [-1 for i in range(101000)]
visited = [False for i in range(101000)]

A, B, C = 0, 0, 0
N, X = map(int, input().split())
for i in range(N) :
    A, B, C = map(int, input().split())
    nextDis[A].append([B, C])
    nextDis[B].append([A, C])

for i in range(1, N + 2):
    if (len(nextDis[i]) == 1) :
        level[i] = 1
        BFS.append([i, 1])

while (len(BFS) != 0) :
    first, second = BFS[0][0], BFS[0][1]
    BFS.popleft()
    done = True
    for i in range(len(nextDis[first])) :
        nextDistrik = nextDis[first][i][0]
        if (level[nextDistrik] == -1) :
            level[nextDistrik] = second + 1
            BFS.append([nextDistrik, second + 1])
            done = False
    if (done) :
        capCity = first

getCost.append([X, 0])
while (len(getCost) != 0) :
    first, second = getCost[0][0], getCost[0][1]
    getCost.popleft()
    if (first == capCity) :
        print(second)
        break
    for i in range(len(nextDis[first])) :
        nextDistrik = nextDis[first][i][0]
        if (level[nextDistrik] > level[first]) :
            getCost.append([nextDistrik, second + nextDis[first][i][1]])