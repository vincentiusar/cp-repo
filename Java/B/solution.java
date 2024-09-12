package B;

import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int p4 = 0, p3 = 0;

        int X = sc.nextInt();
        int D = sc.nextInt();
        int A = sc.nextInt();

        p4 = D / 4;
        D %= 4;

        if (D > 0) {
            if (A + D >= 4) {
                ++p4;
                A -= 4 - D;
                D = 0;
            } else if (A + D >= 3) {
                ++p3;
                A -= 3 - D;
                D = 0;
            }
        }
        System.out.println((int)(((2 * (p4 + p3)) + (0.5 * A) + D) * X));
    }
}