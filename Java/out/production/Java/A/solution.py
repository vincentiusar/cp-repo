n = int(input())

arr = list(map(int, input().split()))

arr.sort(reverse=True)

i = 0
while (i < n and arr[i] == arr[0]) :
    i += 1

print(arr[0], i)