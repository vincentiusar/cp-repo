st = input()
n = len(st)
num = [0 for i in range(n)]

for i in range(n) :
    num[i] = int(st[i]) - int('0')

sumdigit = sum(num)

if (num[n-1] != 0 and num[n-1] != 5) :
    print("Lebih Semangat Lagi")
else :
    if (sumdigit % 9 == 0) :
        print("Semangat 45")
    else :
        if (n > 1) :
            sumbutfirst = (sumdigit - num[0]) % 9
            firstNew = 9 - sumbutfirst
            print("Ayo Semangat 45")
            print("Digit pertama baru:", firstNew)
        else :
            print("Lebih Semangat Lagi")