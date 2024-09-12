import math

theta, r, v, l = map(float, input().split())
	
alfa = theta / 2

jarakLingkaran = r / math.tan(math.radians(alfa))
jarakTongkat = l / math.tan(math.radians(theta))
	
jarakLingkaran = max(jarakLingkaran, jarakTongkat + r)

print("{:.2f}".format((100-jarakLingkaran)/v))