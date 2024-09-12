import math

def pythagoras(a, b):
    return math.sqrt(a*a + b*b)

n = int(input())

X, Y = 0, 0

for i in range(n) :
    dist, deg = map(float, input().split())

    X += dist * math.cos(math.radians(deg))
    Y += dist * math.sin(math.radians(deg))

print("{:.4f}".format(pythagoras(X, Y)), end=" ")
if (X == 0) :
    print("{:.4f}".format(90))
else:
    print("{:.4f}".format(math.degrees(math.atan(Y/X))))