class Point:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y
    def __eq__(self, p):
        return self.x == p.x and self.y == p.y
    def __add__(self, p):
        return Point(self.x + p.x, self.y + p.y)
    def __sub__(self, p):
        return Point(self.x - p.x, self.y - p.y)
    def __mul__(self, d):
        return Point(self.x*d, self.y*d)
    def dot(self, p):
        return self.x*p.x + self.y*p.y
    def cross(self, p):
        return self.x*p.y - self.y*p.x
    def dist2(self):
        return self.x**2 + self.y**2

n = int(input())

vs = []
exist = {}

def addToExist(p, val):
    if p.x in exist:
        exist[p.x][p.y] = val
    else:
        d = dict()
        d[p.y] = val
        exist[p.x] = d

for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    a, b = Point(x1, y1), Point(x2, y2)
    vs.append(b - a)
    addToExist(vs[i], i)

def findThirdSegment(segments):
    # try every possibility of positive/negatives
    for bit in range(4):
        Sum = Point(0, 0)
        for i in range(2):
            if bit & 2**i != 0:
                Sum = Sum + segments[i]
            else: 
                Sum = Sum - segments[i]

        if Sum.x in exist and Sum.y in exist[Sum.x]:
            return exist[Sum.x][Sum.y]
        min1 = Sum*-1
        if min1.x in exist and min1.y in exist[min1.x]:
            return exist[min1.x][min1.y]
    return -1

maxPerim = -1
ans = [0, 0, 0]
for i in range(n):
    for j in range(i + 1, n):
        if vs[i].cross(vs[j]) == 0: continue

        thirdSegment = findThirdSegment([vs[i], vs[j]])
        if thirdSegment != -1:
            perim = vs[i].dist2() + vs[j].dist2() + vs[thirdSegment].dist2()
            if perim > maxPerim:
                maxPerim = perim
                ans = [i + 1, j + 1, thirdSegment + 1]

if maxPerim == -1:
    print(-1)
else:
    print(ans[0], ans[1], ans[2])