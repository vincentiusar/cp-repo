n, m = map(int, input().split())
if (n % 3 == 2 and m % 3 == 2):
    print(n*m//3 - 1)
else:
    print(n*m//3)
