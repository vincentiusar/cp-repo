package H;

import java.math.BigInteger;
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a = sc.nextBigInteger().mod(new BigInteger("1000000007"));
        BigInteger b = sc.nextBigInteger().mod(new BigInteger("1000000007"));
        BigInteger sum = ((a.add(b)).multiply(b.subtract(a).add(new BigInteger("1"))).divide(new BigInteger("2"))).mod(new BigInteger("1000000007"));
        System.out.println(sum);
    }
}