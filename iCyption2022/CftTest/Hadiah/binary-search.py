t = int(input())
for i in range(t):
    v, a, b = map(int, input().split())

    def area(x, y, z):
        return (x*y + y*z + x*z)*2

    L, R = 1, 10**6
    found = False
    while L <= R and not found:
        s = (L + R) // 2
        vol = s*(s + a)*(s + b)
        if vol == v:
            print(area(s, s + a, s + b))
            found = True
        elif vol < v:
            L = s + 1
        else:
            R = s - 1

    if not found: print("MUSTAHIL")
