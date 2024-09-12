S, H, C = map(int, input().split())

def candy(N,C):
 candy = N; wrappers = N; total = candy
 while wrappers >= C:
  candy = (wrappers // C)
  wrappers = candy + (wrappers % C)
  total += candy
 return total

N = S // H
print(candy(N,C))