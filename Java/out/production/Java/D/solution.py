R = int(input())
X, Y, Z = map(int, input().split())
count = 0

while (True) :
    try :
        A, B, C = map(int,input().split())
        if (((X - A) * (X - A)) + ((Y - B) * (Y - B)) + ((Z - C) * (Z - C)) <= (R * R)) :
            count += 1
    except EOFError:
        break

print(count)