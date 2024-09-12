X, D, A = map(int, input().split())

p4 = D // 4
D %= 4
p3 = 0

if (D > 0) :
    if (A + D >= 4) :
        p4 += 1
        A -= 4 - D
        D = 0
    elif (A + D >= 3) :
        p3 += 1
        A -= 3 - D
        D = 0

print(int(((2 * (p4 + p3)) + (0.5 * A) + D) * X))