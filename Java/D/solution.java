package D;

import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int A, B, C, R, X, Y, Z, count = 0;

        R = cin.nextInt();
        X = cin.nextInt(); Y = cin.nextInt(); Z = cin.nextInt();

        while (cin.hasNextInt()) {
            A = cin.nextInt(); B = cin.nextInt(); C = cin.nextInt();
			if (((X - A) * (X - A)) + ((Y - B) * (Y - B)) + ((Z - C) * (Z - C)) <= (R * R)) count++;

        }

        System.out.println(count);
    }
}