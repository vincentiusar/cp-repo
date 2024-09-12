package C;

import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        double EPS = 1e-4;

        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        double X = sc.nextDouble();
        double Y = sc.nextDouble();
        double Z = sc.nextDouble();
        double need = (N - 1) * 2 * Math.sqrt((X * X) + (Y * Y)) + X;
        if (need - Z < EPS) {
            System.out.println("Bisa");
        } else {
            System.out.println("Tidak Bisa");
        }
    }
}