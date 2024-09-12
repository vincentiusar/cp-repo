for _ in range(int(input())):
    S, N = map(int, input().split())
    an = S - (N * N) + N
    if an % N == 0 and (an // N) & 1:
        print("{} {}".format(an // N, (an // N) + 2 * (N - 1)))
    else:
        print("Tidak bisa Nee-chan!")