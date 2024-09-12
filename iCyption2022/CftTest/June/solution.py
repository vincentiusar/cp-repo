def gcd(a, b) :
    if (b == 0):
        return a
    return gcd(b, a % b)

def lcm(a, b) :
    return (a // gcd(a, b)) * b

n, q = map(int, input().split())

v = []
exist = [False for i in range(2501)]
for i in range(1, 51) :
    for j in range(i + 1, 51) :
        LCM = lcm(i, j)
        if (LCM > 100 and not exist[LCM]) :
            v.append(LCM)
            exist[LCM] = True

sume = [0 for i in range(2501)]
sum = 0

num = list(map(int, input().split()))
for j in range(n) :
    sum += num[j]
    for i in range(1, 101) :
        sume[i] += (num[j] if num[j] % i == 0 else 0)

    for i in v:
        sume[i] += (num[j] if num[j] % i == 0 else 0)
    
for j in range(q) :
    m = int(input())
    a = list(map(int, input().split()))

    if (m == 1) :
        print(sume[1] - sume[a[0]])
    else :
        print(sume[1] - sume[a[0]] - sume[a[1]] + sume[lcm(a[0], a[1])])