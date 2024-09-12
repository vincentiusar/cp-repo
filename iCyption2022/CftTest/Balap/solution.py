finish, start_a, start_b, speed_a, speed_b = map(int, input().split())

step_a = ((finish - start_a) // speed_a) + int((finish - start_a) % speed_a != 0)
step_b = ((finish - start_b) // speed_b) + int((finish - start_b) % speed_b != 0)

if (step_a < step_b) :
    print("okawai koto")
elif (step_a > step_b) :
    print("like a man")
else :
    print("dokoisho")