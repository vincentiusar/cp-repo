p, d = [0 for i in range(1000)], [0 for i in range(1000)]

n = int(input())

def inc(a) :
    a += 1
    return (0 if a == n else a)

def dec(a) :
    a -= 1
    return (n-1 if a == -1 else a)

def between(start, finish, x) :
    if (start > finish) :
        return between(start, n-1, x) or between(0, finish, x)
    return (start <= x and x <= finish)

def mx(start, finish) :
    maxPoint, i = 0, start
    while True: 
        maxPoint = max(maxPoint, p[i])
        i = inc(i)
        
        if not (between(start, finish, i) and i != start) : break
    return maxPoint

def count(start, finish, t) :
    if (start == finish and d[t] == start) : return p[start]
    if (not between(start, finish, d[t])) :
        return mx(start, finish) + count (start, finish, t+1)
    
    maxo = 0
    if (between(start, finish, dec(d[t]))) :
        maxo = max(maxo, count(start, dec(d[t]), t+1))
    if (between(start, finish, inc(d[t]))) :
        maxo = max(maxo, count(inc(d[t]), finish, t+1))

    return mx(start, finish) + maxo

p = list(map(int, input().split()))
d = list(item - 1 for item in list(map(int, input().split())))

if (n == 1) :
    print(p[0])
else :
    print(mx(0, n-1) + count(inc(d[0]), dec(d[0]), 1))