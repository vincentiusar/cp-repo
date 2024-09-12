N = int(input())

if (N <= 3) :
    print(-1)
else:
    ans = []
    for i in range(N):
        ans.append(i + 1)

    for i in range(N-2):
        tmp = ans[i]
        ans[i] = ans[i+2]
        ans[i + 2] = tmp

    for i in range(N):
        print(ans[i], end="")
        if (i == N - 1):
            print()
        else:
            print(" ",end="")
