eko = list(map(str, input().split()))
ganesh = list(map(str, input().split()))

delta = 0

for i in range(len(eko)):
    if ((eko[i] == 'h' and ganesh[i] == 'a') or (eko[i] == 'a' and ganesh[i] == 'e') or (eko[i] == 'e' and ganesh[i] == 'h')) :
        delta += 1
    elif (eko[i] != ganesh[i]) :
        delta -= 1

if (delta == 0): print("Draw")
elif (delta > 0): print("Eko wins")
else: print("Ganesh wins")