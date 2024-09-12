def volume(s, V, a, b):
	return s*(s+a)*(s+b) - V

def bisection(lo, hi, V, a, b):
    sol = -1
    mid = 0
    if (((volume(lo,V,a,b) > 0) and (volume(hi,V,a,b) > 0)) or ((volume(lo,V,a,b) < 0) and (volume(hi,V,a,b) < 0))):
        sol = -1

    else:
        found = False
        while ((hi - lo > 1) and (found == False)) :
            mid = (lo + hi )//2;
            if (volume(mid,V,a,b) == 0):
                found = True
                sol = mid
            
            elif (((volume(lo,V,a,b) < 0) and (volume(mid,V,a,b) > 0)) or ((volume(lo,V,a,b) > 0) and (volume(mid,V,a,b) < 0))):
                hi = mid

            else :
                lo = mid
    return sol

def solve(V, a, b) :
	root = bisection(0,1000000,V,a,b)
	return root

def area(s, a, b):
	return 2*(s*(s+a) + s*(s+b) + (s+a)*(s+b))

q = int(input())
for i in range(q) :
    V, a, b = map(int, input().split())
    root = solve(V, a, b)
    if (root != -1):
        print(area(root,a,b))
    else:
        print("MUSTAHIL")