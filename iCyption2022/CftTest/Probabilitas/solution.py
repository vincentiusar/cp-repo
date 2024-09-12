N, L, R = map(int, input().split())

a = list(map(int, input().split()))

a.sort()

def gcd(a, b) :
    if (a == 0) :
        return b
    return gcd(b % a, a)

total = 0

for i in range(N):
    lowerBound, upperBound = -1, -1

    l, r = i + 1, N - 1
    while (l <= r):
        mid = (l + r)//2
        if (a[i] * a[mid] >= L):
            lowerBound, r = mid, mid - 1
        else:
            l = mid + 1

    l, r = i+1, N-1
    while (l <= r) :
        mid = (l + r)//2
        if (a[i] * a[mid] <= R):
            upperBound, l = mid, mid + 1;
        else:
            r = mid - 1

    if (lowerBound != -1 and upperBound != -1) :
        total += (upperBound - lowerBound + 1)

if (total == 0) :
    print("0/1")
else:
    penyebut = N*(N - 1)//2
    fpb = gcd(total, penyebut)
    total //= fpb
    penyebut //= fpb
    print(str(total)+'/'+str(penyebut), end="")