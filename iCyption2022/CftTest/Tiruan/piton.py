r1, c1 = map(int, input().split())
g1 = [[] for i in range(r1)]

for i in range(r1):
    g1[i] = list(map(int, input().split()))

r2, c2 = map(int, input().split())
g2 = [[] for i in range(r2)]
for i in range(r2):
    g2[i] = list(map(int, input().split()))

def rotate90(g):
    r = len(g)
    c = len(g[0])
    tmp = [[0 for i in range(r)] for j in range(c)]
    p1, p2 = 0, r-1
    for i in range(r):
        for j in range(c):
            tmp[p1][p2] = g[i][j]
            p1 = (p1 + 1) % c
        p2 -= 1
    return tmp

def flipHor(g):
    tmp = []
    for v in g:
        tmp.append(v[::-1])
    return tmp

def flipVer(g):
    r = len(g)
    c = len(g[0])
    tmp = [[0 for i in range(c)] for j in range(r)]
    p1 = r-1
    for i in range(r):
        for j in range(c): tmp[p1][j] = g[i][j]
        p1 -= 1
    return tmp

def isEqual(a, b):
    R1, R2 = len(a), len(b)
    if R1 != R2: return False

    C1, C2 = len(a[0]), len(b[0])
    if C1 != C2: return False

    for i in range(R1):
        for j in range(C1):
            if a[i][j] != b[i][j]:
                return False
    return True

serupa = False
for i in range(4):
    if isEqual(g1, g2): serupa = True
    if isEqual(flipHor(g1), g2): serupa = True
    if isEqual(flipVer(g1), g2): serupa = True
    g1 = rotate90(g1)

if serupa:
    print("SERUPA")
else:
    print("TAK SERUPA")
