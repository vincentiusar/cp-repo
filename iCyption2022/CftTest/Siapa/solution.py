a, b = 0, 0
n = int(input())

def isPalindrome(s1) :
    s2 = s1[::-1]
    if(s1==s2) :
        return True
    return False

for i in range(1, n+1):
    s = str(input())
    if (isPalindrome(s)) :
        if (i%2 == 1): 
            a += 1
        else :
            b += 1 

if(a>b) : 
    print("Andi menang")
elif (a<b) : 
    print("Budi menang")
else : 
    print("Gaada yang menang")