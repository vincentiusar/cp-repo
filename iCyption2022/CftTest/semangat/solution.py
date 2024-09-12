def sumOf(n) :
    sum, first = 0, 0
    while (n > 0) :
        sum += n % 10
        first = n
        n //= 10
    return sum, first

n = int(input())

sum, first = sumOf(n)

if (n % 10 != 0 and n % 10 != 5) :
    print("Lebih Semangat Lagi")
else :
    if (sum % 9 == 0) :
        print("Semangat 45")
    else :
        if (n > 9) :
            sumbutfirst = (sum - first) % 9
            firstNew = 9 - sumbutfirst
            print("Ayo Semangat 45")
            print("Digit pertama baru:", firstNew)
        else :
            print("Lebih Semangat Lagi")