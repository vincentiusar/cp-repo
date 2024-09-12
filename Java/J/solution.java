package J;

import java.util.Scanner;

public class solution {

    static long gcd(long a, long b) {
        return a == 0 ? b : gcd(b % a, a);
    }

    static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long M = sc.nextInt();
        long C = sc.nextInt();

        System.out.println(lcm(M, C));
    }
}