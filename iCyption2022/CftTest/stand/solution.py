n = int(input())
if (n == 0):
    print('0')
else:
    harga = list(map(int, input().split()))

    totalSewa = [0 for i in range(n + 1)]

    totalSewa[0] = 0
    totalSewa[1] = harga[0]
    for i in range(2, n + 1):
        totalSewa[i] = max(totalSewa[i - 1], harga[i - 1] + totalSewa[i - 2])
    print(totalSewa[n])

