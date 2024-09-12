import sys
print(sys.setrecursionlimit(1000000000))

def g(s) :
    i = 0
    new_str = ""
    while i < len(s) - 1 :
        new_str = new_str + s[i+1]
        i += 1
    return new_str

def f(s) :
    if len(s) == 0 :
        return str("")
    elif len(s) == 1 :
        return s
    else :
        return f(g(s)) + (s[0])

def h(n, s) :
    while n != 1 :
        if n % 2 == 0 :
            n /= 2
        else :
            n = 3*n + 1
        s = f(s)
    return s

def power(x, y) :
    if y == 0 :
        return 1
    else :
        return x * power(x, y - 1)

print(h(1, "fruits"))
print(h(2, "fruits"))
print(h(5, "fruits"))
print(h(power(2, 1000000000000000), "fruits"))
print(h(power(2, 9831050005000007), "fruits"))