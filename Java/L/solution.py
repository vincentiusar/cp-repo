def ask(x):
    print(x)

    res = input()

    return res

l, r = 1, 1000000000
while (l <= r) :
    mid = (l + r)//2
    ans = ask(mid)
    if (ans == ">"):
        l = mid + 1
    elif (ans == "<"):
        r = mid - 1
    else:
        break