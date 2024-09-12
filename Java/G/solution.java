package G;

import java.math.BigInteger;
import java.util.Scanner;

public class solution {
    static BigInteger a = new BigInteger("2"), b = new BigInteger("4"), zero = new BigInteger("0");
    public static boolean checkperfectsquare(BigInteger n) {
        BigInteger L = new BigInteger("1"), R = n;
        while (L.compareTo(R) <= 0) {
            BigInteger mid = L.add(R.subtract(L).divide(a));
            BigInteger sqr = mid.multiply(mid);
            if (sqr.equals(n)) {
                return true;
            } else if (sqr.compareTo(n) < 0) {
                L = mid.add(new BigInteger("1"));
            } else {
                R = mid.subtract(new BigInteger("1"));
            }
        }
        return false;
    }

    public static BigInteger valueSqrt(BigInteger n) {
        BigInteger L = new BigInteger("1"), R = n;
        while (L.compareTo(R) <= 0) {
            BigInteger mid = L.add(R.subtract(L).divide(a));
            BigInteger sqr = mid.multiply(mid);
            if (sqr.equals(n)) {
                return sqr;
            } else if (sqr.compareTo(n) < 0) {
                L = mid.add(new BigInteger("1"));
            } else {
                R = mid.subtract(new BigInteger("1"));
            }
        }
        return new BigInteger("-1");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger K = sc.nextBigInteger(), L = sc.nextBigInteger();

        if (!K.mod(a).equals(zero)) { System.out.println("MUSTAHIL"); return; }

        BigInteger S = K.divide(a);
        BigInteger discriminant = S.multiply(S).subtract(L.multiply(b));

        if (discriminant.compareTo(zero) < 0) { System.out.println("MUSTAHIL"); return; }

        if (!checkperfectsquare(discriminant)) { System.out.println("MUSTAHIL"); return; }

        BigInteger rdisc = valueSqrt(discriminant);
        BigInteger aduh = new BigInteger(rdisc.toString());
        if (!(S.add(aduh)).mod(a).equals(new BigInteger("0"))) {
            System.out.println("MUSTAHIL"); return;
        } else {
            System.out.println("MUNGKIN"); return;
        }

    }
}