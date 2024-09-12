a, b = map(int,input().split())
sum = ((a+b)*(b-a+1)//2) % (10**9+7)
print(sum)