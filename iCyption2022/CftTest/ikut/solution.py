a = int(input())
peserta = []
for i in range(a):
    nama, jmlSoal = input().split()
    jmlSoal = int(jmlSoal)
    peserta.append({"nama":nama, "jmlSoal":jmlSoal})
b = int(input())

min = 101
for p in peserta:
    if p["jmlSoal"]<min and p["jmlSoal"]>=b:
        guru = p["nama"]
        min = p["jmlSoal"]

if min==101:
    print("Tidak bisa berguru", end="")
else:
    print(guru, end="")
