import java.util.*;
import java.math.BigInteger;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static BigInteger gcd(BigInteger a, BigInteger b) {
        if (a.compareTo(new BigInteger("0")) == 0)
            return b;
        return gcd(b.mod(a), a);
    }

    public static void main(String[] args) {
        BigInteger N = cin.nextBigInteger(), L = cin.nextBigInteger(), R = cin.nextBigInteger();

        BigInteger a[] = new BigInteger[N.intValue()];
        for (int i = 0; i < N.intValue(); i++)
            a[i] = cin.nextBigInteger();

        Arrays.sort(a);

        BigInteger total = new BigInteger("0");
        for (int i = 0; i < N.intValue(); i++) {
            int lowerBound = -1, upperBound = -1;

            int l = i+1, r = N.intValue()-1;
            while (l <= r) {
                int mid = (l + r)/2;
                if ((a[i].multiply(a[mid])).compareTo(L) >= 0) {
                    lowerBound = mid; r = mid - 1;
                } else
                    l = mid + 1;
            }

            l = i+1; r = N.intValue()-1;
            while (l <= r) {
                int mid = (l + r)/2;
                if ((a[i].multiply(a[mid])).compareTo(R) <= 0) {
                    upperBound = mid; l = mid + 1;
                } else
                    r = mid - 1;
            }

            if (lowerBound != -1 && upperBound != -1)
                total = total.add(BigInteger.valueOf(upperBound - lowerBound + 1));
        }

        if (total.compareTo(new BigInteger("0")) == 0) {
            System.out.println("0/1");
            return;
        }

        BigInteger penyebut = N.multiply(N.subtract(new BigInteger("1"))).divide(new BigInteger("2"));
        BigInteger fpb = gcd(total, penyebut);
        total = total.divide(fpb); penyebut = penyebut.divide(fpb);
        System.out.println(total + "/" + penyebut);
    }
}
