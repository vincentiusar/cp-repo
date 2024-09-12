import java.util.*;
import java.lang.Math.*;

public class solution {

    static Scanner cin = new Scanner(System.in);

    public static double pythagoras(double a, double b) {
        return Math.sqrt(a*a + b*b);
    }

    public static void main(String[] args) {
        long n = cin.nextLong();

        double X = 0, Y = 0;

        for (long i = 0; i < n; i++) {
            double dist = cin.nextDouble(), deg = cin.nextDouble();

            X += dist * Math.cos(Math.toRadians(deg));
            Y += dist * Math.sin(Math.toRadians(deg));
        }

        System.out.println(String.format("%.4f %.4f", pythagoras(X, Y), Math.toDegrees(Math.atan(Y/X)) ));
    }
}