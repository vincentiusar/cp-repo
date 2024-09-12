import math

a, b = map(int, input().split())

i = 0
while (i < 20) :
    j = 0
    while (j < 20) :
        print(math.pow(17081945, i) % math.pow(25, j) != 0)
        j += 1
    i += 1
# if (math.pow(17081945, b) % math.pow(25, a) != 0) :
#     print("Tidak")
# else :
#     print("Ya")