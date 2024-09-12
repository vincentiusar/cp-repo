dp = [1000000000 for i in range(1000001)]

a, b, c = map(int, input().split())
t = int(input())

dp[a] = 1
dp[b] = 1
dp[c] = 1
dp[0] = 0

for i in range(1000000):
    if (i - a >= 0) : dp[i] = min(dp[i-a] + 1, dp[i])
    if (i - b >= 0) : dp[i] = min(dp[i-b] + 1, dp[i])
    if (i - c >= 0) : dp[i] = min(dp[i-c] + 1, dp[i])

while (t > 0) :
    n = int(input())

    if (dp[n] == 1000000000) :
        print(0)
    else :
        print(dp[n])
    
    t -= 1