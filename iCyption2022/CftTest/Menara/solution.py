n = int(input())

tinggi = 0
dipakai = 0
tambah = 2

while (dipakai <= n) :
    dipakai += tambah
    tambah += 3
    tinggi += 1

print(tinggi - 1, n-dipakai+tambah-3)