def getSum(n) :
    sum = 0
    while (n > 0) :
        sum += n % 10
        n //= 10
    return sum

def checkPrime(n) :
    if (n == 1) : return False

    i = 2
    while (i * i <= n) :
        if (n % i == 0) :
            return False
        i += 1
    return True

n, m = map(int, input().split(" "))

sum = 0
for i in range(n, m+1) :
    if (checkPrime(getSum(i))) :
        sum += i
print(sum)